float4x4 matWorldViewProj;

struct VS_OUTPUT
{
	float4 vPos : POSITION;
	float2 vTextCoord :TEXCOORD0;
};

//������Ⱦ��������

VS_OUTPUT VS(float4 Pos:POSITION,float3 vNormal : NORMAL,float2 vTextCoord : TEXCOORD0)
{
	//����λ��
	
	VS_OUTPUT Out=(VS_OUTPUT)0;
	Out.vPos=mul(Pos,matWorldViewProj);
	
	Out.vTextCoord=vTextCoord;
	
	return Out;	
	
}

//����

technique TShader
{
	pass P0
	{
		VertexShader=compile vs_2_0 VS();
	}
}