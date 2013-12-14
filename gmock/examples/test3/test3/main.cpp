//
//  main.cpp
//  test3
//
//  The following code is from the webpage
//  http://yuanmuqiuyu2000.i.sohu.com/blog/view/151715259.htm
//
//  Created by wolf76 on 2/26/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <gmock/gmock.h>
using testing::Return;
using testing::_;
using testing::Gt;

class Turtle {
public:
    virtual ~Turtle(){}
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};

class MockTurtle: public Turtle {
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};

class CPainter{
public:
    CPainter():m_ptl(NULL){}
    void SetTurtle(Turtle* ptl) {
        m_ptl = ptl;
    }
    
    void Square(int w) // Draw a square
    {
        if (!m_ptl || w<=0) return;
        m_ptl->PenDown();
        m_ptl->Forward(w);
        m_ptl->Turn(90);
        m_ptl->Forward(w);
        m_ptl->Turn(90);
        m_ptl->Forward(w);
        m_ptl->Turn(90);
        m_ptl->Forward(w);
        m_ptl->Turn(90);
        m_ptl->PenUp();
    }
    
private:
    Turtle *m_ptl;
};

TEST(PainterTest, SquareTest)
{
    MockTurtle turtle;
    EXPECT_CALL(turtle, Forward(_)).Times(0);
    EXPECT_CALL(turtle, Forward(Gt(0))).Times(4);
    
    EXPECT_CALL(turtle, Turn(90)).Times(4);
    EXPECT_CALL(turtle, PenUp());
    EXPECT_CALL(turtle, PenDown());
    
    CPainter pt;
    pt.SetTurtle(&turtle);
    pt.Square(10);
    pt.Square(0);
}

TEST(PainterTest, CanDrawSomething)
{
    MockTurtle turtle;
    EXPECT_CALL(turtle, GetX())
    .Times(testing::AtLeast(5))
    .WillOnce(Return(100))
    .WillOnce(Return(150))
    .WillRepeatedly(Return(200));
    
    EXPECT_EQ(100, turtle.GetX());
    EXPECT_EQ(150, turtle.GetX());
    EXPECT_EQ(200, turtle.GetX());
    EXPECT_EQ(200, turtle.GetX());
    EXPECT_EQ(200, turtle.GetX());
}

int main(int argc, const char * argv[])
{
    testing::InitGoogleMock(&argc, (char **)argv);
    int r = RUN_ALL_TESTS();
    return r;
}
