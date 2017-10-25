//
//  ViewController.m
//  LineDemo
//
//  Created by liubo on 17/4/21.
//  Copyright © 2017年 wanshenglong. All rights reserved.
//

#import "ViewController.h"

#import "UUChart.h"

@interface ViewController ()<UUChartDataSource>{
    UUChart *_chartView;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    [self createUI];
}

#pragma mark - 创建视图
- (void)createUI{
    
    _chartView = [[UUChart alloc]initWithFrame:CGRectMake(40, 100, self.view.frame.size.width-80,446) dataSource:self style:UUChartStyleLine];
    
    [_chartView showInView:self.view];
}

- (NSArray *)getXTitles:(int)num
{
    NSMutableArray *xTitles = [NSMutableArray array];
    for (int i = 0; i<num; i++) {
        
        NSString * str = [NSString stringWithFormat:@"%d时",i+9];
        
        [xTitles addObject:str];
    }
    return xTitles;
}

#pragma mark - @required
// 横坐标标题数组
- (NSArray *)chartConfigAxisXLabel:(UUChart *)chart{
    
    return [self getXTitles:10];
}

// 数值多重数组
- (NSArray *)chartConfigAxisYValue:(UUChart *)chart
{
    NSArray *ary = @[@"23",@"42",@"25",@"15",@"30",@"42",@"32",@"40",@"42",@"25"];
    
 
    return @[ary];
}

#pragma mark - @optional
//颜色数组
- (NSArray *)chartConfigColors:(UUChart *)chart
{
    return @[[UUColor green],[UUColor red],[UUColor brown]];
}

// 显示数值范围
- (CGRange)chartRange:(UUChart *)chart
{
    return CGRangeMake(180, 0);
}

#pragma mark 折线图专享功能

// 标记数值区域
- (CGRange)chartHighlightRangeInLine:(UUChart *)chart
{
    return CGRangeZero;
}

// 判断显示横线条
- (BOOL)chart:(UUChart *)chart showHorizonLineAtIndex:(NSInteger)index
{
    return YES;
}

// 判断显示最大最小值
- (BOOL)chart:(UUChart *)chart showMaxMinAtIndex:(NSInteger)index
{
    return NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
