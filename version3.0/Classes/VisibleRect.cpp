// VisibleRect.cpp
// 星月倾心贡献~~~~

/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "VisibleRect.h"

USING_NS_CC;

Rect VisibleRect::s_visibleRect;  // 初始化静态变量：可视区域

// 初始化
void VisibleRect::lazyInit()
{
	// no lazy init
	// Useful if we change the resolution in runtime
	// 获得：可视区域
	s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
}

// 获得可视区域
Rect VisibleRect::getVisibleRect()
{
	lazyInit();
	return s_visibleRect;
}

// 窗口：左中
Point VisibleRect::left()
{
	lazyInit();
	return Point(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

// 窗口：右中
Point VisibleRect::right()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

// 窗口：上中
Point VisibleRect::top()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y + s_visibleRect.size.height);
}

// 窗口：下中
Point VisibleRect::bottom()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y);
}

// 窗口：中中
Point VisibleRect::center()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width / 2, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
}

// 窗口：左上
Point VisibleRect::leftTop()
{
	lazyInit();
	return Point(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height);
}

// 窗口：右上
Point VisibleRect::rightTop()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height);
}

// 窗口：左下
Point VisibleRect::leftBottom()
{
	lazyInit();
	return s_visibleRect.origin;
}

// 窗口：右下
Point VisibleRect::rightBottom()
{
	lazyInit();
	return Point(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y);
}