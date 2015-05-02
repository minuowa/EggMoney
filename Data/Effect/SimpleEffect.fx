float4x4    matWorldViewProj; 
texture   TexObj;
float4 materialAmbient;
float4 materialDiffuse;
float4x4 matWorld;
 
bool bOpenLight;
bool bUseMaterialOnly;
 
//--------------------------------------------------------------
// ������ɫ������ṹ
//--------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Position   : POSITION;
    float2 TextureUV  : TEXCOORD0;  //��������
	float4 Color	:COLOR;  
};


//-----------------------------------------------------------------
// ������ɫ����ں���
//-----------------------------------------------------------------
VS_OUTPUT VS(float4 Pos : POSITION, float3 Normal: NORMAL,float2 vTexCoord0 : TEXCOORD0)
{
    //����λ��
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
    //����
   Out.TextureUV = vTexCoord0; 
    return Out;
}

//-----------------------------------------------------------------
// ���������
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
	
	//�������ɫ
	OutColor=tex2D(Sampler2D,psIn.TextureUV);


	if(bOpenLight)
	{
		if(!bUseMaterialOnly)
		{
			//������ɫ��������ɫ���
			OutColor=OutColor*psIn.Color;
		}
		else
		{
			//û�������Mesh��������ʵ���ɫ
			OutColor=psIn.Color;
		}	
	}

	
	//�������յ�ʱ�������Ϊ�������ɫ
	
	return OutColor;
}




//--------------------------------------------------------------
//  �ַ�
//--------------------------------------------------------------
technique TShader
{
    pass P0
    {
        VertexShader = compile vs_2_0 VS();
        
        PixelShader	= compile ps_2_0 PS();
    }
}



