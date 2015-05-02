#pragma once
class ContentPlugin:public GPlugin
{
public:
	DeclarePlugin(ContentPlugin);

	ContentPlugin(void);
	~ContentPlugin(void);

	virtual void onCallBack( const CXDelegate& d, CXEventArgs* e );

};

