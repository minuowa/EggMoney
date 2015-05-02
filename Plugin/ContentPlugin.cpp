#include "stdafx.h"
#include "ContentPlugin.h"


ContentPlugin::ContentPlugin(void)
{
	Content::Game.mDelegateOnInitEnd+=this;
}


ContentPlugin::~ContentPlugin(void)
{
	Content::Game.mDelegateOnInitEnd-=this;
}

void ContentPlugin::onCallBack( const CXDelegate& d, CXEventArgs* e )
{
	if (d==Content::Game.mDelegateOnInitEnd)
	{
		//创建世界坐标系
		GWorldCorrd* corrd = new GWorldCorrd();
		CXASSERT_RETURN ( corrd->recreate() );
		Content::Scene.addStaticObj ( corrd );
	}
}
