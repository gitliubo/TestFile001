//
//  ZCWScrollNumView.h
//  车险达人
//
//  Created by zangcw on 12-9-6.
//  Copyright (c) 2012年 ZCW. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    ZCWScrollNumAnimationTypeNone,
    ZCWScrollNumAnimationTypeNormal,
    ZCWScrollNumAnimationTypeFromLast,
    ZCWScrollNumAnimationTypeRand,
    ZCWScrollNumAnimationTypeFast
} ZCWScrollNumAnimationType;

@interface ZCWScrollDigitView : UIView {
    CGFloat _oneDigitHeight;
}

@property (retain, nonatomic) UIView *backgroundView;
@property (retain, nonatomic) UILabel *label;
@property (readonly, nonatomic) NSUInteger digit;
@property (retain, nonatomic) UIFont *digitFont;

- (void)setDigitAndCommit:(NSUInteger)aDigit;
- (void)setDigitFromLast:(NSUInteger)aDigit;
- (void)setDigit:(NSUInteger)aDigit from:(NSUInteger)last;
- (void)setDigitFast:(NSUInteger)aDigit;
- (void)setRandomScrollDigit:(NSUInteger)aDigit length:(NSUInteger)length;

- (void)commitChange;

- (void)didConfigFinish;

@end

@interface ZCWScrollNumView : UIView {
    NSMutableArray *_numberViews;
}

// 数字一共多少位
@property (nonatomic) NSUInteger numberSize;
// 每个数字左右两侧的间距
@property (nonatomic) CGFloat splitSpaceWidth;
// 每个数字距离父视图顶部和底部的距离
@property (nonatomic) CGFloat topAndBottomPadding;
@property (readonly, nonatomic) NSUInteger numberValue;
// 背景图(整个父视图大小)
@property (retain, nonatomic) UIView *backgroundView;
// 数字视图
@property (retain, nonatomic) UIView *digitBackgroundView;
// 数字字体
@property (retain, nonatomic) UIFont *digitFont;
@property (readonly, nonatomic) NSArray *numberViews;
// 数字颜色
@property (retain, nonatomic) UIColor *digitColor;
@property (nonatomic) NSUInteger randomLength;

// 选择不同的风格,同时带有动画的去设置需要显示的数字值
- (void)setNumber:(NSUInteger)number withAnimationType:(ZCWScrollNumAnimationType)type animationTime:(NSTimeInterval)timeSpan;

// 完成基本设置后触发该方法，显示到界面
- (void)didConfigFinish;

@end
