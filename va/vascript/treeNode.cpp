/**
 * =====================================================================================
 *       @file    treeNode.cpp
 *
 *       @brief   '
 *
 *       @author  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *       @version 1.0
 *       @date    01/30/2011 10:59:08 AM
 *
 *       Revision none
 *       Compiler gcc
 *       Company  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
#include "debprintf.h"
void Node::setNext(Node* o)
{
	this -> mNext = o;
    if(o){
        o -> mPrevious = this;
        if(this->mParent) o->parent(this->mParent);
    }
}

void Node::addChild(Node* child_)
{
    if(mChild) {
        appandChild(child_);
    }else{
        addFirstChild(child_);
    }
    debprintf("this->%0x; child->%0x\n",  this, child_ );
}

void Node::appandChild(Node* child_)
{
    Widget* lastSib = mChild->mPrevious;
    lastSib -> setNext(child_);
    child_ ->mNext = 0;
    mChild -> mPrevious = child_;
    child_->parent(this) ;	
}

void Node::addFirstChild(Node* child_)
{
    this-> mChild = child_;
    mChild -> mNext = NULL;
    mChild -> mPrevious = mChild;
    child_->parent ( this);
}


