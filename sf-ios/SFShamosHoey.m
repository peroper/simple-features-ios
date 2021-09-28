//
//  SFShamosHoey.m
//  sf-ios
//
//  Created by Brian Osborn on 1/12/18.
//  Copyright © 2018 NGA. All rights reserved.
//

#import "SFShamosHoey.h"
#import "SFGeometryUtils.h"
#import "SFEventQueue.h"
#import "SFSweepLine.h"

@implementation SFShamosHoey

+(BOOL) simplePolygon: (SFPolygon *) polygon{
    return [self simplePolygonRings:[polygon lineStrings]];
}

+(BOOL) simplePolygonPoints: (NSArray<SFPoint *> *) points{
    SFLineString *ring = [[SFLineString alloc] init];
    [ring.points addObjectsFromArray:points];
    return [self simplePolygonRing:ring];
}

+(BOOL) simplePolygonRingPoints: (NSArray<NSArray<SFPoint *>*> *) pointRings{
    NSMutableArray<SFLineString *> *rings = [[NSMutableArray alloc] init];
    for(NSArray<SFPoint *> *points in pointRings){
        SFLineString *ring = [[SFLineString alloc] init];
        [ring.points addObjectsFromArray:points];
        [rings addObject:ring];
    }
    return [self simplePolygonRings:rings];
}

+(BOOL) simplePolygonRing: (SFLineString *) ring{
    NSMutableArray<SFLineString *> *rings = [[NSMutableArray alloc] init];
    [rings addObject:ring];
    return [self simplePolygonRings:rings];
}

+(BOOL) simplePolygonRings: (NSArray<SFLineString *> *) rings{
    
    BOOL simple = rings.count > 0;
    
    NSMutableArray<SFLineString *> *ringCopies = [[NSMutableArray alloc] init];
    for(int i = 0; i < rings.count; i++){
        
        SFLineString *ring = [rings objectAtIndex:i];
        
        // Copy the ring
        SFLineString *ringCopy = [[SFLineString alloc] init];
        [ringCopy.points addObjectsFromArray:ring.points];
        [ringCopies addObject:ringCopy];
        
        // Remove the last point when identical to the first
        NSMutableArray<SFPoint *> *ringCopyPoints = ringCopy.points;
        if(ringCopyPoints.count >= 3){
            SFPoint *first = [ringCopyPoints objectAtIndex:0];
            SFPoint *last = [ringCopyPoints objectAtIndex:ringCopyPoints.count - 1];
            if([first.x compare:last.x] == NSOrderedSame && [first.y compare:last.y] == NSOrderedSame){
                [ringCopyPoints removeObjectAtIndex:ringCopyPoints.count - 1];
            }
        }
        
        // Verify enough ring points
        if (ringCopyPoints.count < 3) {
            simple = NO;
            break;
        }
        
        // Check holes to make sure the first point is in the polygon
        if (i > 0) {
            SFPoint *firstPoint = [ringCopyPoints objectAtIndex:0];
            if(![SFGeometryUtils point:firstPoint inPolygonRing:[rings objectAtIndex:0]]){
                simple = NO;
                break;
            }
            // Make sure the hole first points are not inside of one another
            for (int j = 1; j < i; j++) {
                NSArray<SFPoint *> *holePoints = [rings objectAtIndex:j].points;
                if([SFGeometryUtils point:firstPoint inPolygonPoints:holePoints]
                   || [SFGeometryUtils point:[holePoints objectAtIndex:0] inPolygonPoints:ringCopyPoints]){
                    simple = NO;
                    break;
                }
            }
            if (!simple) {
                break;
            }
        }
    }
    
    // If valid polygon rings
    if (simple) {
        
        SFEventQueue *eventQueue = [[SFEventQueue alloc] initWithRings:ringCopies];
        SFSweepLine *sweepLine = [[SFSweepLine alloc] initWithRings:ringCopies];
        
        for (SFEvent *event in eventQueue.events) {
            if(event.type == SF_ET_LEFT){
                SFSegment *segment = [sweepLine addEvent:event];
                if([sweepLine intersectWithSegment:segment andSegment:segment.above]
                   || [sweepLine intersectWithSegment:segment andSegment:segment.below]){
                    simple = NO;
                    break;
                }
            } else {
                SFSegment *segment = [sweepLine findEvent:event];
                if([sweepLine intersectWithSegment:segment.above andSegment:segment.below]){
                    simple = NO;
                    break;
                }
                [sweepLine removeSegment:segment];
            }
        }
    }
    
    return simple;
    
}

@end
