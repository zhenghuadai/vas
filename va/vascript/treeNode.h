#ifndef __Node_HEADER__
#define __Node_HEADER__
class Node
{
protected:
    Node* mParent;
    Node* mNext;
    Node* mPrevious;
    Node* mChild;
public:
    Node(){init();};

    void setParent(Node* o){ mParent = o;}
    void setNext(Node* o);
    Node* parent(){return mParent;}
    Node* next()  { return mNext;}
    Node* child() {return mChild;}
    void parent(Node* o) { mParent = o;}
    void next(Node* o){ mNext = o;}
    void addChild(Node*);
private:
    void appandChild(Node* child_);
    void addFirstChild(Node* child_);
    //!
public:
    virtual bool hasChild(){ return (mChild !=NULL);}
private:
    void init(){mParent = mNext = mPrevious = mChild =  NULL;}

};
#endif
