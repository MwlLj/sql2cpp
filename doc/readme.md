[TOC]

## python说明
- 版本: python 3

## 基本用法
### 创建表
- 示例:
```sql
#create tables
/*
create table if not exists t_open_door_record (
    record_uuid varchar(64),
    info json,
    is_send boolean
);
*/
#end

#create tables
/*
create table if not exists t_device_alarm_info (
    alarm_uuid varchar(64),
    info json,
    is_send boolean
);
*/
#end
```
- 示例说明:
    - 使用以下语法创建一个或者多个语句
    ```sql
    #create tables
    /*
    */
    #end
    ```
    - create tables 中的语句每次都会运行 (在类的构造中执行)

### 完整示例
- 示例
```sql
/*
    @bref 根据时段uuid获取时段的引用计数
    @is_brace true
    @in_isarr true
    @out_isarr true
    @in periodUuid: string
    @out periodUuid: string
    @out count: int
*/
#define getPeriodReferenceCountByPeriodUuid
select * from t_period_reference_count
where period_uuid = {0};
#end
```
- 示例说明
    - is_brace
        - true: 使用 {0} {1} {2} ... 占位
        - false/不存在该字段: 使用 ? .. 占位
    - in_isarr
        - true: 输入是数组
        - false: 输入是单个值
    - out_isarr
        - true: 输出是数组
        - false: 输出是单个值
    - @in: 所有的 @in 构成一个输入类
    - @out: 所有的 @out 构成一个输出类

### padding语法
- 示例
```sql
/*
    @bref 获取时段
    @is_brace true
    @in_isarr false
    @out_isarr true
    @in padding[padding]: string
    @in defaulted[ and defaulted = {}]: int
    @in f1[ and f1 = '{}']: string
    @out periodUuid: string
    @out periodName: string
    @out defaulted: bool
    @out source: string
    @out content: string
    @out extInfo: string
    @out version: int
    @out createTime: string
    @out updateTime: string
    @out defaultPeriodType: int
*/
#define getPeriodInfoByPadding
select * from t_period_info
where 1=1 {0};
#end
```
- 示例说明
    - 指定一个 [padding] 类型的字段, 如:
        - @in padding[padding]: string)
    - 使用 1=1 占位
    - 在有padding的情况下, 在可有可无的字段的中括号中填写拼接的语句, 如:
        - @in defaulted[ and defaulted = {}]: int
        - @in f1[ and f1 = '{}']: string
        - 如果代码中调用了 setDefaulted, 则最后的sql为:
            - select * from t_period_info where 1=1  and defaulted = 1;

### cond语法
- 示例
```sql
/*
    @bref 获取时段
    @is_brace true
    @in_isarr false
    @out_isarr true
    @in condition[cond]: string
    @out periodUuid: string
    @out periodName: string
    @out defaulted: bool
    @out source: string
    @out content: string
    @out extInfo: string
    @out version: int
    @out createTime: string
    @out updateTime: string
    @out defaultPeriodType: int
*/
#define getPeriodInfo
select * from t_period_info {0};
#end
```
- 示例说明
    - 指定一个 [cond] 字段, 如:
        - @in condition[cond]: string
    - 代码中将需要拼接的字段组合在一个 std::string 中, 然后调用 setCondition 设置拼接字符串

### 指定输入输出类名语法
- 目的
    - 默认是以 #define 后面的名称加上Input/Output构成输入/输出的类名
    - 这样做会出现无法编写模板代码, 所以出现指定输入/输出类名的语法
- 应用
    - 多个接口可以指定同一个名称的输入/输出类, 这样就可以构成函数重载 (函数名相同, 但是参数不同)
- 示例
```sql
/*
    @bref 删除黑名单信息
    @is_brace true
    @in_isarr true
    @out_isarr false
    @in_class deleteBlacklistIssueInfoInput
    @out_class deleteBlacklistIssueInfoOutput
    @in blacklistUuid: string
*/
#define deleteDataDetailInfo
delete from t_blacklist_info
where blacklist_uuid = {0};
#end
```
- 示例说明
    - in_class: 后面指定输入的类名
    - out_class: 后面指定输出的类名

### sub语法
- 作用
    - 使一个方法中可以执行多条sql
- 示例
```sql
/*
    @bref 删除全部组织关系
    @is_brace true
    @in_isarr false
    @out_isarr false
*/
#define deleteAllOrgRelInfo
delete from t_org_rel;
#end

/*
    @bref 将人员照片记录移动到最后
    @is_brace true
    @in_isarr false
    @out_isarr false
    @in photoUuid: string
    @sub addStaffPhotoInfo[1]
*/
#define moveStaffPhotoToLast
delete from t_staff_photo_info where photo_uuid = {0};
#end

/*
    @bref 新增组织关系信息
    @is_brace true
    @in_isarr true
    @out_isarr false
    @in_class addOrganizationRelIssueInfo
    @in relationUuid: string
    @in relationType: string
    @in extraInfo: string
    @in version: int
    @in createTime: string
    @in updateTime: string
    @in remarks: string
    @in orgUuid: string
    @in staffUuid: string
    @sub deleteAllOrgRelInfo[-1]
    @sub moveStaffPhotoToLast[1]
*/
#define addDataDetailInfo
insert into t_org_rel values({0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8});
#end
```
- 示例说明
    - 解析内部定义 addDataDetailInfo 方法的索引为0, sub后的 [-1] 就是在 0 的左边, sub后的 [1] 就是在 0 的右边
      最后的执行顺序就是:
      1. deleteAllOrgRelInfo
      2. addDataDetailInfo
      3. moveStaffPhotoToLast
