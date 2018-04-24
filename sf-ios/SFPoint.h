//
//  SFPoint.h
//  sf-ios
//
//  Created by Brian Osborn on 6/2/15.
//  Copyright (c) 2015 NGA. All rights reserved.
//

#import "SFGeometry.h"

/**
 * A single location in space. Each point has an X and Y coordinate. A point MAY
 * optionally also have a Z and/or an M value.
 */
@interface SFPoint : SFGeometry

/**
 *  X coordinate
 */
@property (nonatomic, strong) NSDecimalNumber * x;

/**
 *  Y coordinate
 */
@property (nonatomic, strong) NSDecimalNumber * y;

/**
 *  Z coordinate
 */
@property (nonatomic, strong) NSDecimalNumber * z;

/**
 *  M coordinate
 */
@property (nonatomic, strong) NSDecimalNumber * m;

/**
 *  Initialize
 *
 *  @return new point
 */
-(instancetype) init;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *
 *  @return new point
 */
-(instancetype) initWithXValue: (double) x andYValue: (double) y;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *
 *  @return new point
 */
-(instancetype) initWithX: (NSDecimalNumber *) x andY: (NSDecimalNumber *) y;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *
 *  @return new point
 */
-(instancetype) initWithX: (NSDecimalNumber *) x andY: (NSDecimalNumber *) y andZ: (NSDecimalNumber *) z;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *
 *  @return new point
 */
-(instancetype) initWithXValue: (double) x andYValue: (double) y andZ: (NSDecimalNumber *) z;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *
 *  @return new point
 */
-(instancetype) initWithXValue: (double) x andYValue: (double) y andZValue: (double) z;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *  @param m m coordinate
 *
 *  @return new point
 */
-(instancetype) initWithX: (NSDecimalNumber *) x andY: (NSDecimalNumber *) y andZ: (NSDecimalNumber *) z andM: (NSDecimalNumber *) m;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *  @param m m coordinate
 *
 *  @return new point
 */
-(instancetype) initWithXValue: (double) x andYValue: (double) y andZ: (NSDecimalNumber *) z andM: (NSDecimalNumber *) m;

/**
 *  Initialize
 *
 *  @param x x coordinate
 *  @param y y coordinate
 *  @param z z coordinate
 *  @param m m coordinate
 *
 *  @return new point
 */
-(instancetype) initWithXValue: (double) x andYValue: (double) y andZValue: (double) z andMValue: (double) m;

/**
 *  Initialize
 *
 *  @param hasZ has z coordinate
 *  @param hasM has m coordinate
 *  @param x    x coordinate
 *  @param y    y coordinate
 *
 *  @return new point
 */
-(instancetype) initWithHasZ: (BOOL) hasZ andHasM: (BOOL) hasM andX: (NSDecimalNumber *) x andY: (NSDecimalNumber *) y;

/**
 *  Initialize
 *
 *  @param hasZ has z coordinate
 *  @param hasM has m coordinate
 *  @param x    x coordinate
 *  @param y    y coordinate
 *
 *  @return new point
 */
-(instancetype) initWithHasZ: (BOOL) hasZ andHasM: (BOOL) hasM andXValue: (double) x andYValue: (double) y;

/**
 *  Set the x value
 *
 *  @param x   x coordinate
 */
-(void) setXValue: (double) x;

/**
 *  Set the y value
 *
 *  @param y   y coordinate
 */
-(void) setYValue: (double) y;

/**
 *  Set the z value
 *
 *  @param z   z coordinate
 */
-(void) setZValue: (double) z;

/**
 *  Set the m value
 *
 *  @param m   m coordinate
 */
-(void) setMValue: (double) m;

@end
