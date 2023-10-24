# MarkUP

#### 简介

MarkUP 是一个通过 `\033` 控制字符，用 `C++` 实现的 Linux 渲染语法，支持闪烁、**加粗**、_斜体_，~~划掉~~，和下划线

函数原型：`std::string markup::convert(std::string str,std::string default_style="")`

参数：

- `std::string str` MarkUP代码
- `std::string default_style=""`（可选参数）：默认的格式（可以指定颜色等）

返回值：处理后的字符串

#### MarkUP语法

- `!!!xxx!!!` 显示为闪烁的`xxx`
- `___xxx___` 显示为带下划线的`xxx`
- `---xxx---` 显示为~~xxx~~
- `///xxx///` 显示为*xxx*
- `***xxx***` 显示为**xxx**

- 可以叠加使用，比如 `---xxx***xxx---xxx***` 会显示为 ~~xxx~~**~~xxx~~xxx**

#### 实例

见 demo.cpp