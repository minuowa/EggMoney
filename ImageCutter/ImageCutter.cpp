#include "stdafx.h"
#include "ImageCutter.h"

ImageCutter gImageCutter;

ImageCutter::ImageCutter ( void )
    : mNode ( nullptr )
    , mSelectNode ( nullptr )
    , mImageID ( 0 )
    , mOnlyDisplayAlpha ( false )
    , mW ( 0 )
    , mH ( 0 )
{

}


ImageCutter::~ImageCutter ( void )
{
    this->clear();
}

bool ImageCutter::loadTexture ( const char* image )
{
    CXASSERT_RETURN_FALSE ( image );
    CXFileName filename ( image );
    mFile = filename.getOrignalName();
    if ( !recreate() )
    {
        mDelegateLoadTextureFailed.trigger();
    }
    return true;
}

bool ImageCutter::recreate()
{
    try
    {
        Content::UIMgr.recreateRootNode();
        this->clear();
        Content::TextureMgr.destoryResource ( mFile );
        mNode = new GUINode();
        mNode->recreate();
        mNode->setTexture ( mFile );
        mNode->setState ( eUINodeState_CanScale, true );
        //mNode->setState ( eUINodeState_CorrectPixel, true );
        GTexture* txtProp = mNode->getTexture();
        CXASSERT_RETURN_FALSE ( txtProp );
        mNode->setWH ( txtProp->width(), txtProp->height() );
        mW = txtProp->width();
        mH = txtProp->height();
        GUINode* root = Content::UIMgr.getRootNode();
        root->setState ( eUINodeState_CanScale, true );
        root->addChild ( mNode );

        GRectCursor* cursor = new GRectCursor;
        cursor->recreate();
        cursor->setTarget ( mNode );
        mNode->addChild ( cursor );
        mNode->setRenderTech ( mOnlyDisplayAlpha ?
                               GRenderTech_PrimiteWithPictureAlphaFromTextureColorFromDiffuse
                               : GRenderTech_PrimiteWithPictureAlpha
                             );
        createSelector();
        mDelegateLoadTextureSucessed.trigger();
    }
    catch ( ... )
    {
        assert ( 0 && "memory leak" );
        mDelegateLoadTextureFailed.trigger();
    }
    return true;
}

void ImageCutter::offset ( long x, long y )
{
    if ( mNode )
    {
        Content::UIMgr.getRootNode()->offset ( x, y );
    }
}

void ImageCutter::clear()
{
    mNode = nullptr;
    mSelectNode = nullptr;
}


void ImageCutter::createSelector()
{
    mSelectNode = new GTapeNode();
    mSelectNode->setColor ( Color_Pure_Green );
    mSelectNode->setState ( eObjState_Render, false );
    mSelectNode->setState ( eUINodeState_CanScale, true );
    mSelectNode->setState ( eUINodeState_CorrectPixel, true );
    mSelectNode->recreate();
    mNode->addChild ( mSelectNode );
}

void ImageCutter::clearSelector()
{
    mSelectNode = nullptr;
}
void ImageCutter::setSelectorRightButtom ( long r, long b )
{
    if ( mSelectNode )
    {
        mSelectNode->setRB ( r, b );
    }
}

void ImageCutter::beginSelect ( long x, long y )
{
    if ( !mSelectNode )
        return;
    mSelectNode->setXY ( x, y );
    mSelectNode->setWH ( 0, 0 );
    mSelectNode->setState ( eObjState_Render, true );
}

void ImageCutter::correct()
{
    if ( mSelectNode )
    {
        mSelectNode->correct();
        mSelectNode->clamp ( mNode->getRect() );
    }
}
float fparam = 0.1f;

void ImageCutter::scale ( long x, long y, double scale )
{
    if ( !mNode )
        return;

    auto root = Content::UIMgr.getRootNode();
    double oldfs = root->getScaleX();
    double fs = root->getScaleX() + scale;
    if ( fs < 1.0f )
        return;
    root->scale ( fs, x, y );
}

void ImageCutter::offsetSelector ( long x, long y )
{
    if ( mSelectNode )
    {
        x *= mSelectNode->getScaleX();
        y *= mSelectNode->getScaleX();
        mSelectNode->offset ( x, y );
        mSelectNode->correct();
        mSelectNode->clamp ( mNode->getRect() );
    }
}

void ImageCutter::dragSelcotr ( long x, long y )
{
    if ( mSelectNode )
    {
        mSelectNode->drag ( x, y );
    }
}

GTapeNode* ImageCutter::getSelcotr() const
{
    return mSelectNode;
}

int ImageCutter::getImageID() const
{
    return mImageID;
}

void ImageCutter::setImageID ( int id )
{
    mImageID = id;
}

const char* ImageCutter::getFile() const
{
    return mFile.c_str();
}

void ImageCutter::onlyDisplayAlpha ( bool only )
{
    mOnlyDisplayAlpha = only;
    if ( mNode )
    {
        mNode->setRenderTech ( mOnlyDisplayAlpha ?
                               GRenderTech_PrimiteWithPictureAlphaFromTextureColorFromDiffuse
                               : GRenderTech_PrimiteWithPictureAlpha
                             );
    }
}

int ImageCutter::getW() const
{
    return mW;
}

int ImageCutter::getH() const
{
    return mH;
}
