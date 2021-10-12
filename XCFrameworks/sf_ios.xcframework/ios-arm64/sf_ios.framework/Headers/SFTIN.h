//
//  SFTIN.h
//  sf-ios
//
//  Created by Brian Osborn on 6/2/15.
//  Copyright (c) 2015 NGA. All rights reserved.
//

#import "SFPolyhedralSurface.h"

/**
 * A tetrahedron (4 triangular faces), corner at the origin and each unit
 * coordinate digit.
 */
@interface SFTIN : SFPolyhedralSurface

/**
 *  Initialize
 *
 *  @return new tin
 */
-(instancetype) init;

/**
 *  Initialize
 *
 *  @param hasZ has z values
 *  @param hasM has m values
 *
 *  @return new tin
 */
-(instancetype) initWithHasZ: (BOOL) hasZ andHasM: (BOOL) hasM;

/**
 * Initialize
 *
 * @param polygons
 *            list of polygons
 *
 *  @return new tin
 */
-(instancetype) initWithPolygons: (NSMutableArray<SFPolygon *> *) polygons;

/**
 * Initialize
 *
 * @param polygon
 *            polygon
 *
 *  @return new tin
 */
-(instancetype) initWithPolygon: (SFPolygon *) polygon;

@end
