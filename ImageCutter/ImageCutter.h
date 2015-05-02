#pragma once
class ImageCutter
{
public:
	CXDelegate mDelegateLoadTextureSucessed;
	CXDelegate mDelegateLoadTextureFailed;
    ImageCutter ( void );
    ~ImageCutter ( void );
    bool loadTexture ( const char* image );
    void offset ( long x, long y );
    void offsetSelector ( long x, long y );
    void clear();
    void beginSelect ( long x, long y );
    void setSelectorRightButtom ( long r, long b );
    void correct();
    void scale ( long x, long y, double scale );
    void dragSelcotr ( long dx, long dy );
    GTapeNode*  getSelcotr() const;
	void setImageID(int id);
	int getImageID()const;
	const char* getFile() const;
	void onlyDisplayAlpha(bool only);
	int getW() const;
	int getH() const;
protected:
    bool recreate();
    void createSelector();
    void clearSelector();
    uString mFile;
    GUINode* mNode;
    GTapeNode* mSelectNode;
	int mW;
	int mH;
	int mImageID;
	bool mOnlyDisplayAlpha;
};
extern ImageCutter gImageCutter;

