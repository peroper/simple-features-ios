//
//  SFGeometryEnvelopeBuilder.h
//  sf-ios
//
//  Created by Brian Osborn on 6/1/15.
//  Copyright (c) 2015 NGA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SFGeometryEnvelope.h"
#import "SFGeometry.h"

/**
 *  Builds an envelope from a Geometry
 */
@interface SFGeometryEnvelopeBuilder : NSObject

/**
 *  Build geometry envelope with geometry
 *
 *  @param geometry geometry to build envelope from
 *
 *  @return geometry envelope
 */
+(SFGeometryEnvelope *) buildEnvelopeWithGeometry: (SFGeometry *) geometry;

/**
 *  Expand existing geometry envelope with a geometry
 *
 *  @param envelope geometry envelope to expand
 *  @param geometry geometry to build envelope from
 */
+(void) buildEnvelope: (SFGeometryEnvelope *) envelope andGeometry: (SFGeometry *) geometry;

@end
