//
//  SFGeometryUtils.h
//  sf-ios
//
//  Created by Brian Osborn on 4/14/17.
//  Copyright © 2017 NGA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SFGeometry.h"
#import "SFPoint.h"
#import "SFLineString.h"
#import "SFPolygon.h"
#import "SFGeometryTypes.h"

/**
 * Utilities for Geometry objects
 *
 * @author osbornb
 */
@interface SFGeometryUtils : NSObject

/**
 * Get the dimension of the Geometry, 0 for points, 1 for curves, 2 for
 * surfaces. If a collection, the largest dimension is returned.
 *
 * @param geometry
 *            geometry object
 * @return dimension (0, 1, or 2)
 */
+(int) dimensionOfGeometry: (SFGeometry *) geometry;

/**
 * Get the Pythagorean theorem distance between two points
 *
 * @param point1
 *            point 1
 * @param point2
 *            point 2
 * @return distance
 */
+(double) distanceBetweenPoint1: (SFPoint *) point1 andPoint2: (SFPoint *) point2;

/**
 * Get the centroid point of a 2 dimensional representation of the Geometry
 * (balancing point of a 2d cutout of the geometry). Only the x and y
 * coordinate of the resulting point are calculated and populated. The
 * resulting SFPoint.z and SFPoint.m values will always be nil.
 *
 * @param geometry
 *            geometry object
 * @return centroid point
 */
+(SFPoint *) centroidOfGeometry: (SFGeometry *) geometry;

/**
 * Minimize the geometry using the shortest x distance between each connected set of points.
 * The resulting geometry point x values will be in the range: 
 *   (3 * min value &lt;= x &lt;= 3 * max value
 *
 * Example: For WGS84 provide a max x of 180.0.
 * Resulting x values will be in the range: -540.0 &lt;= x &lt;= 540.0
 *
 * Example: For web mercator provide a world width of 20037508.342789244.
 * Resulting x values will be in the range: -60112525.028367732 &lt;= x &lt;= 60112525.028367732
 *
 * @param geometry
 *            geometry
 * @param maxX
 *            max positive x value in the geometry projection
 */
+(void) minimizeGeometry: (SFGeometry *) geometry withMaxX: (double) maxX;

/**
 * Normalize the geometry so all points outside of the min and max value range are
 * adjusted to fall within the range.
 *
 * Example: For WGS84 provide a max x of 180.0.
 * Resulting x values will be in the range: -180.0 &lt;= x &lt;= 180.0.
 *
 * Example: For web mercator provide a world width of 20037508.342789244.
 * Resulting x values will be in the range: -20037508.342789244 &lt;= x &lt;= 20037508.342789244.
 *
 * @param geometry
 *            geometry
 * @param maxX
 *            max positive x value in the geometry projection
 */
+(void) normalizeGeometry: (SFGeometry *) geometry withMaxX: (double) maxX;

/**
 * Simplify the ordered points (representing a line, polygon, etc) using the Douglas Peucker algorithm
 * to create a similar curve with fewer points. Points should be in a meters unit type projection.
 * The tolerance is the minimum tolerated distance between consecutive points.
 *
 * @param points
 *            geometry points
 * @param tolerance
 *            minimum tolerance in meters for consecutive points
 * @return simplified points
 */
+ (NSArray<SFPoint *> *) simplifyPoints: (NSArray<SFPoint *> *) points withTolerance : (double) tolerance;

/**
 * Calculate the perpendicular distance between the point and the line represented by the start and end points.
 * Points should be in a meters unit type projection.
 *
 * @param point
 *            point
 * @param lineStart
 *            point representing the line start
 * @param lineEnd
 *            point representing the line end
 * @return distance in meters
 */
+ (double) perpendicularDistanceBetweenPoint: (SFPoint *) point lineStart: (SFPoint *) lineStart lineEnd: (SFPoint *) lineEnd;

/**
 * Check if the point is in the polygon
 *
 * @param point
 *            point
 * @param polygon
 *            polygon
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygon: (SFPolygon *) polygon;

/**
 * Check if the point is in the polygon
 *
 * @param point
 *            point
 * @param polygon
 *            polygon
 * @param epsilon
 *            epsilon line tolerance
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygon: (SFPolygon *) polygon withEpsilon: (double) epsilon;

/**
 * Check if the point is in the polygon ring
 *
 * @param point
 *            point
 * @param ring
 *            polygon ring
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygonRing: (SFLineString *) ring;

/**
 * Check if the point is in the polygon ring
 *
 * @param point
 *            point
 * @param ring
 *            polygon ring
 * @param epsilon
 *            epsilon line tolerance
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygonRing: (SFLineString *) ring withEpsilon: (double) epsilon;

/**
 * Check if the point is in the polygon points
 *
 * @param point
 *            point
 * @param points
 *            polygon points
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygonPoints: (NSArray<SFPoint *> *) points;

/**
 * Check if the point is in the polygon points
 *
 * @param point
 *            point
 * @param points
 *            polygon points
 * @param epsilon
 *            epsilon line tolerance
 * @return true if in the polygon
 */
+(BOOL) point: (SFPoint *) point inPolygonPoints: (NSArray<SFPoint *> *) points withEpsilon: (double) epsilon;

/**
 * Check if the point is on the polygon edge
 *
 * @param point
 *            point
 * @param polygon
 *            polygon
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonEdge: (SFPolygon *) polygon;

/**
 * Check if the point is on the polygon edge
 *
 * @param point
 *            point
 * @param polygon
 *            polygon
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonEdge: (SFPolygon *) polygon withEpsilon: (double) epsilon;

/**
 * Check if the point is on the polygon ring edge
 *
 * @param point
 *            point
 * @param ring
 *            polygon ring
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonRingEdge: (SFLineString *) ring;

/**
 * Check if the point is on the polygon ring edge
 *
 * @param point
 *            point
 * @param ring
 *            polygon ring
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonRingEdge: (SFLineString *) ring withEpsilon: (double) epsilon;

/**
 * Check if the point is on the polygon ring edge points
 *
 * @param point
 *            point
 * @param points
 *            polygon points
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonPointsEdge: (NSArray<SFPoint *> *) points;

/**
 * Check if the point is on the polygon ring edge points
 *
 * @param point
 *            point
 * @param points
 *            polygon points
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the polygon edge
 */
+(BOOL) point: (SFPoint *) point onPolygonPointsEdge: (NSArray<SFPoint *> *) points withEpsilon: (double) epsilon;

/**
 * Check if the polygon outer ring is explicitly closed, where the first and
 * last point are the same
 *
 * @param polygon
 *            polygon
 * @return true if the first and last points are the same
 */
+(BOOL) closedPolygon: (SFPolygon *) polygon;

/**
 * Check if the polygon ring is explicitly closed, where the first and last
 * point are the same
 *
 * @param ring
 *            polygon ring
 * @return true if the first and last points are the same
 */
+(BOOL) closedPolygonRing: (SFLineString *) ring;

/**
 * Check if the polygon ring points are explicitly closed, where the first
 * and last point are the same
 *
 * @param points
 *            polygon ring points
 * @return true if the first and last points are the same
 */
+(BOOL) closedPolygonPoints: (NSArray<SFPoint *> *) points;

/**
 * Check if the point is on the line
 *
 * @param point
 *            point
 * @param line
 *            line
 * @return true if on the line
 */
+(BOOL) point: (SFPoint *) point onLine: (SFLineString *) line;

/**
 * Check if the point is on the line
 *
 * @param point
 *            point
 * @param line
 *            line
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the line
 */
+(BOOL) point: (SFPoint *) point onLine: (SFLineString *) line withEpsilon: (double) epsilon;

/**
 * Check if the point is on the line represented by the points
 *
 * @param point
 *            point
 * @param points
 *            line points
 * @return true if on the line
 */
+(BOOL) point: (SFPoint *) point onLinePoints: (NSArray<SFPoint *> *) points;

/**
 * Check if the point is on the line represented by the points
 *
 * @param point
 *            point
 * @param points
 *            line points
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the line
 */
+(BOOL) point: (SFPoint *) point onLinePoints: (NSArray<SFPoint *> *) points withEpsilon: (double) epsilon;

/**
 * Check if the point is on the path between point 1 and point 2
 *
 * @param point
 *            point
 * @param point1
 *            path point 1
 * @param point2
 *            path point 2
 * @return true if on the path
 */
+(BOOL) point: (SFPoint *) point onPathPoint1: (SFPoint *) point1 andPoint2: (SFPoint *) point2;

/**
 * Check if the point is on the path between point 1 and point 2
 *
 * @param point
 *            point
 * @param point1
 *            path point 1
 * @param point2
 *            path point 2
 * @param epsilon
 *            epsilon line tolerance
 * @return true if on the path
 */
+(BOOL) point: (SFPoint *) point onPathPoint1: (SFPoint *) point1 andPoint2: (SFPoint *) point2 withEpsilon: (double) epsilon;

/**
 * Determine if the geometries contain a Z value
 *
 * @param geometries
 *            list of geometries
 * @return true if has z
 */
+(BOOL) hasZ: (NSArray<SFGeometry *> *) geometries;

/**
 * Determine if the geometries contain a M value
 *
 * @param geometries
 *            list of geometries
 * @return true if has m
 */
+(BOOL) hasM: (NSArray<SFGeometry *> *) geometries;

/**
 * Get the parent type hierarchy of the provided geometry type starting with
 * the immediate parent. If the argument is GEOMETRY, an empty list is
 * returned, else the final type in the list will be GEOMETRY.
 *
 * @param geometryType
 *            geometry type
 * @return list of increasing parent types
 */
+(NSArray<NSNumber *> *) parentHierarchyOfType: (enum SFGeometryType) geometryType;

/**
 * Get the parent Geometry Type of the provided geometry type
 *
 * @param geometryType
 *            geometry type
 * @return parent geometry type or null if argument is GEOMETRY (no parent
 *         type)
 */
+(enum SFGeometryType) parentTypeOfType: (enum SFGeometryType) geometryType;

/**
 * Get the child type hierarchy of the provided geometry type.
 *
 * @param geometryType
 *            geometry type
 * @return child type hierarchy, null if no children
 */
+(NSDictionary<NSNumber *, NSDictionary *> *) childHierarchyOfType: (enum SFGeometryType) geometryType;

/**
 * Get the immediate child Geometry Types of the provided geometry type
 *
 * @param geometryType
 *            geometry type
 * @return child geometry types, empty list if no child types
 */
+(NSArray<NSNumber *> *) childTypesOfType: (enum SFGeometryType) geometryType;

/**
 * Encode the geometry to data
 *
 * @param geometry
 *            geometry
 * @return encoded dta
 */
+(NSData *) encodeGeometry: (SFGeometry *) geometry;

/**
 * Decode the data into a geometry
 *
 * @param data
 *            encoded data
 * @return geometry
 */
+(SFGeometry *) decodeGeometry: (NSData *) data;

@end
