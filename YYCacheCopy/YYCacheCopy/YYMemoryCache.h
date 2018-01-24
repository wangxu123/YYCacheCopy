//
//  YYMemoryCache.h
//  YYCacheCopy
//
//  Created by Xu on 2018/1/16.
//  Copyright © 2018年 . All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 LRU 淘汰算法（最近最久未使用）
 采用双向链表的做法。
 每一次存储数据的时候都插入在头节点，进行清除缓存可以选择在后台清除还是主线程。
 自由控制清楚缓存的时间，成本，总量，存储时间期限，还有自动释放的时间周期
 */

NS_ASSUME_NONNULL_BEGIN
@interface YYMemoryCache : NSObject
@property (nullable, copy) NSString *name;
@property (readonly) NSUInteger totalCount;
@property (readonly) NSUInteger totalCost;
@property NSUInteger countLimit;
@property NSUInteger costLimit;
@property NSTimeInterval ageLimit;
@property NSTimeInterval autoTrimInterval;
@property BOOL shouldRemoveAllObjectsOnMemoryWaining;
@property BOOL shouldRemoveAllObjectsWhenEnteringBackground;
@property (nullable, copy) void(^didReceiveMemoryWainingBlock)(YYMemoryCache *cache);
@property (nullable, copy) void(^didEnterBackgroundBlock)(YYMemoryCache *cache);
@property BOOL releaseOnMainThread;
@property BOOL releaseAsynchronously;

- (BOOL)containsObjectsForKey:(id)key;
- (nullable id)objectForKey:(id)key;
- (void)setObject:(nullable id)object forKey:(id)key;
- (void)setObject:(nullable id)object forKey:(id)key withCost:(NSUInteger)cost;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;

- (void)trimToCount:(NSUInteger)count;
- (void)trimToCost:(NSUInteger)cost;
- (void)trimToAge:(NSTimeInterval)age;
@end
NS_ASSUME_NONNULL_END
