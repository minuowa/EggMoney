float4x4    matWorldViewProj; 
texture   TexObj;
float4 materialAmbient;
float4 materialDiffuse;
float4x4 matWorld;
 
bool bOpenLight;
bool bUseMaterialOnly;
 
//--------------------------------------------------------------
// 顶点着色器输出结构
//--------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Position   : POSITION;
    float2 TextureUV  : TEXCOORD0;  //纹理坐标
	float4 Color	:COLOR;  
};


//-----------------------------------------------------------------
// 顶点着色器入口函数
//-----------------------------------------------------------------
VS_OUTPUT VS(float4 Pos : POSITION, float3 Normal: NORMAL,float2 vTexCoord0 : TEXCOORD0)
{
    //顶点位置
    VS_OUTPUT Out = (VS_OUTPUT)0;      
   
    Out.Position = mul(Pos, matWorldViewProj);
   
   //float4 ambient={0.6f,0.6f,0.6f,0.6f};
   //float4 diffuse={1.0f,1.0f,1.0f,1.0f};
   
   float4 ambient={1.0f,1.0f,1.0f,0.6f};
   float4 diffuse={2.0f,2.0f,2.0f,1.0f};
   float4 tmp={-1.0f,0.5f,0.0f,0.0f};
   float4 vecLight=normalize(tmp);
   float4 Norm=normalize(mul(Normal,matWorld));

   Out.Color=materialAmbient*ambient+materialDiffuse*saturate(dot(vecLight,Norm))*diffuse;
    //纹理
   Out.TextureUV = vTexCoord0; 
    return Out;
}

//-----------------------------------------------------------------
// 纹理采样器
//-----------------------------------------------------------------

sampler2D Sampler2D=sampler_state
{
	Texture=<TexObj>;
	MinFilter=LINEAR;
	MagFilter=LINEAR;
	MipFilter=LINEAR;
	AddressU=WRAP;
	AddressV=WRAP;
};

float4 PS(VS_OUTPUT psIn) :COLOR
{
	float4 OutColor=0;
	
	//纹理的颜色
	OutColor=tex2D(Sampler2D,psIn.TextureUV);


	if(bOpenLight)
	{
		if(!bUseMaterialOnly)
		{
			//材质颜色与纹理颜色混合
			OutColor=OutColor*psIn.Color;
		}
		else
		{
			//没有纹理的Mesh，输出材质的颜色
			OutColor=psIn.Color;
		}	
	}

	
	//不开光照的时候，输出的为纹理的颜色
	
	return OutColor;
}




//--------------------------------------------------------------
//  手法
//--------------------------------------------------------------
technique TShader
{
    pass P0
    {
        VertexShader = compile vs_2_0 VS();
        
        PixelShader	= compile ps_2_0 PS();
    }
}



