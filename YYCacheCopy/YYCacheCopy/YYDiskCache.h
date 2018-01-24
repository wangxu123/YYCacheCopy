//
//  YYDiskCache.h
//  YYCacheCopy
//
//  Created by Xu on 2018/1/16.
//  Copyright © 2018年 . All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@interface YYDiskCache : NSObject
@property (nullable, copy) NSString *name;
@property (readonly) NSString *path;
@property (readonly) NSUInteger inLineThreshold;
@property (nullable, copy) NSData *(^customArchiveBlock)(id object);
@property (nullable, copy) id (^customUnarchiveBlock)(NSData *data);
@property (nullable, copy) NSString *(^customFileNameBlcok)(NSString *key);

@property NSUInteger countLimit;
@property NSUInteger costLimit;
@property NSUInteger ageLimit;
@property NSUInteger freeDiskSpaceLimit;
@property NSTimeInterval autoTrimInterval;
@property BOOL errorLogsEnabled;

/**
 @discussion UNAVAILABLE_ATTRIBUTE 无效的属性
 @discussion NS_DESIGNATED_INITIALIZER 特定的初始化
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;


- (nullable instancetype)initWithPath:(NSString *)path;
- (nullable instancetype)initWithPath:(NSString *)path
                      inlineThreshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;


- (BOOL)containsObjectForKey:(NSString *)key;
- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;
- (nullable id<NSCoding>)objectForKey:(NSString *)key;
- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> _Nullable object))block;
- (void)setObject:(nullable id<NSCoding>)object forkey:(NSString *)key;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(void(^)(void))block;
- (void)removeObjectForKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;
- (void)removeAllObjects;
- (void)removeAllObjectsWithBlcok:(void(^)(void))block;
- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount,int totalCount))progress endBlock:(nullable void(^)(BOOL error))end;
- (NSInteger)totalCount;
- (void)totalCountWithBlock:(void(^)(NSInteger totalCount))block;
- (NSInteger)totalCost;
- (void)totalCostWithBlock:(void(^)(NSInteger totalCost))blcok;
- (void)trimToCount:(NSUInteger)count;
- (void)trimToCount:(NSUInteger)count withBlock:(void(^)(void))block;
- (void)trimToCost:(NSUInteger)cost;
- (void)trimToCost:(NSUInteger)cost withBlock:(void(^)(void))blcok;
- (void)trimToAge:(NSTimeInterval)age;
- (void)trimToAge:(NSTimeInterval)age withBlock:(void(^)(void))blcok;
+ (nullable NSData *)getExtendDataFromObject:(id)object;
+ (void)setExtendedData:(nullable NSData *)extendedData toObject:(id)object;
@end
NS_ASSUME_NONNULL_END
