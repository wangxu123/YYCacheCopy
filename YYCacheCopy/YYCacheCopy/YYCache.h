//
//  YYCache.h
//  YYCacheCopy
//
//  Created by Xu on 2018/1/16.
//  Copyright © 2018年 . All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 
 FOUNDATION_EXPORT 兼容C++
 
 #if defined(__cplusplus)
 #define FOUNDATION_EXTERN extern "C"
 #else
 #define FOUNDATION_EXTERN extern
 #endif
 */

#if __has_include(<YYCache/YYCache.h>) /// 是否可以导入头文件，用来预防导入不存在的头文件
FOUNDATION_EXPORT double YYCacheVersionNumber;
FOUNDATION_EXPORT const unsigned char YYCacheVersionString[];
#import <YYCache/YYMemoryCache.h>
#import <YYCache/YYDiskCache.h>
#import <YYCache/YYKVStorage.h>
#elif __has_include(<YYWebImage/YYCache.h>)
#import <YYWebImage/YYMemoryCache.h>
#import <YYWebImage/YYDiskCache.h>
#import <YYWebImage/YYKVStorage.h>
#else
#import "YYMemoryCache.h"
#import "YYDiskCache.h"
#import "YYKVStorage.h"
#endif

NS_ASSUME_NONNULL_BEGIN // 默认非空
@interface YYCache : NSObject
@property (copy, readonly) NSString *name;
@property (strong, readonly) YYMemoryCache *memoryCache;
@property (strong, readonly) YYDiskCache *diskCache;
- (nullable instancetype)initWithName:(NSString *)name;
- (nullable instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;// 指定实例化方法
+ (nullable instancetype)cacheWithName:(NSString *)name;
+ (nullable instancetype)cacheWithPath:(NSString *)path;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (BOOL)containsObjectForKey:(NSString *)key;
- (void)containsObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key,BOOL contains))block;
- (nullable id<NSCoding>)objectForKey:(NSString *)key;
- (void)objectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key, id<NSCoding> object))block;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withBlock:(nullable void(^)(void))block;
- (void)removeObjectForKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key withBlock:(nullable void(^)(NSString *key))block;
- (void)removeAllObjects;
- (void)removeAllObjectsWithBlock:(void(^)(void))block;
- (void)removeAllObjectsithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                endBlock:(nullable void(^)(BOOL error))end;

@end
NS_ASSUME_NONNULL_END
