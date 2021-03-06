xof 0303txt 0032
template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}


Material PDX21_-_Default {
 1.000000;1.000000;1.000000;1.000000;;
 3.200000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "U000027.tga";
 }
}

Frame Box01 {
 

 FrameTransformMatrix {
  201.118256,0.000000,0.000000,0.000000,0.000000,201.118256,0.000000,0.000000,0.000000,0.000000,201.118256,0.000000,-0.000000,0.000000,-0.000000,1.000000;;
 }

 Frame {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.002564,-0.013823,0.003024,1.000000;;
  }

  Mesh  {
   41;
   0.031563;0.083347;-0.011146;,
   -0.036103;0.000796;0.000600;,
   -0.031317;0.071394;-0.001660;,
   0.035318;0.000814;0.000729;,
   0.036290;0.044352;0.033285;,
   -0.000960;0.000848;-0.036755;,
   -0.036043;0.041323;0.024511;,
   0.016871;0.076257;0.024659;,
   0.049142;0.045345;0.001357;,
   -0.033564;0.029351;-0.037527;,
   -0.000741;0.000835;0.030967;,
   -0.033142;0.054891;-0.031343;,
   0.000037;0.042577;0.038054;,
   0.000000;0.028947;-0.043442;,
   0.035677;0.050187;-0.025786;,
   0.033137;0.082224;0.012690;,
   0.029255;0.022665;0.027740;,
   -0.033614;0.000795;0.017305;,
   0.015297;0.079440;-0.022219;,
   -0.049010;0.041983;-0.001548;,
   0.000633;0.087933;0.000155;,
   0.043445;0.028837;0.018586;,
   0.032945;0.000853;-0.014328;,
   -0.030424;0.069048;-0.015131;,
   -0.018313;0.028793;-0.044458;,
   0.018898;0.030150;0.038017;,
   0.042859;0.031641;-0.013547;,
   0.041498;0.067938;-0.012183;,
   -0.036043;0.041758;-0.036158;,
   0.018000;0.086234;0.012950;,
   -0.042692;0.026431;0.015652;,
   0.016951;0.088064;-0.011616;,
   -0.033614;0.000829;-0.020144;,
   -0.018313;0.027744;0.034211;,
   -0.041005;0.056184;0.010250;,
   -0.033142;0.054662;0.019985;,
   0.000116;0.071976;0.025224;,
   -0.016138;0.077145;0.011001;,
   0.033823;0.000841;0.017245;,
   0.018313;0.032274;-0.036700;,
   -0.017487;0.000850;-0.037984;;
   71;
   3;11,13,24;,
   3;13,11,18;,
   3;25,10,16;,
   3;10,25,33;,
   3;28,11,24;,
   3;17,33,6;,
   3;33,17,10;,
   3;31,20,29;,
   3;8,21,3;,
   3;39,22,5;,
   3;22,39,14;,
   3;23,19,34;,
   3;19,23,28;,
   3;35,37,2;,
   3;37,35,36;,
   3;15,8,27;,
   3;8,15,21;,
   3;7,12,25;,
   3;18,14,39;,
   3;9,19,28;,
   3;19,9,30;,
   3;32,9,40;,
   3;3,21,38;,
   3;23,20,31;,
   3;36,35,12;,
   3;9,24,40;,
   3;26,22,14;,
   3;14,27,26;,
   3;29,36,7;,
   3;36,29,37;,
   3;15,7,4;,
   3;1,9,32;,
   3;9,1,30;,
   3;31,0,18;,
   3;0,31,29;,
   3;18,0,14;,
   3;34,6,35;,
   3;6,34,19;,
   3;30,6,19;,
   3;2,23,34;,
   3;23,2,20;,
   3;15,4,21;,
   3;21,4,16;,
   3;26,3,22;,
   3;28,23,11;,
   3;18,23,31;,
   3;23,18,11;,
   3;24,5,40;,
   3;5,24,13;,
   3;4,7,25;,
   3;4,25,16;,
   3;27,8,26;,
   3;26,8,3;,
   3;0,15,27;,
   3;0,27,14;,
   3;28,24,9;,
   3;15,29,7;,
   3;0,29,15;,
   3;30,17,6;,
   3;30,1,17;,
   3;25,12,33;,
   3;33,12,6;,
   3;34,35,2;,
   3;12,35,6;,
   3;7,36,12;,
   3;2,37,20;,
   3;29,20,37;,
   3;10,38,16;,
   3;21,16,38;,
   3;13,18,39;,
   3;39,5,13;;

   MeshNormals  {
    41;
    -0.634981;0.487963;-0.598908;,
    0.174968;0.062115;-0.982613;,
    -0.132552;0.073876;-0.988419;,
    0.086123;0.604535;-0.791909;,
    0.233367;-0.151429;0.960525;,
    -0.022031;-0.320395;0.947028;,
    0.505238;-0.358791;0.784859;,
    -0.347920;-0.093545;0.932846;,
    -0.682162;0.204098;-0.702138;,
    -0.746402;-0.314090;0.586713;,
    -0.641324;0.148480;0.752766;,
    0.061921;0.939634;-0.336532;,
    -0.261766;0.964905;0.020881;,
    0.059529;0.917402;0.393483;,
    0.997359;0.061205;0.039091;,
    0.893920;-0.185854;0.407878;,
    0.950197;-0.309049;-0.040177;,
    0.461339;-0.020292;-0.886992;,
    0.802931;-0.297849;-0.516321;,
    0.282808;-0.265441;-0.921716;,
    0.634146;0.130765;-0.762076;,
    -0.604343;0.705933;-0.369361;,
    -0.999130;0.024066;-0.034066;,
    -0.798163;0.497128;0.340293;,
    -0.521893;0.487580;0.699924;,
    -0.443734;0.773858;0.451933;,
    -0.684586;0.726477;0.059770;,
    -0.236102;0.583050;0.777372;,
    0.614308;0.696821;0.370225;,
    0.848453;0.373165;-0.375334;,
    0.092484;0.581379;0.808360;,
    -0.104046;0.181566;0.977859;,
    -0.727432;-0.177500;-0.662824;,
    -0.906493;-0.174904;0.384291;,
    -0.930150;-0.189882;-0.314271;,
    -0.304003;-0.302291;-0.903439;,
    0.750287;-0.359040;0.555122;,
    0.879003;-0.183984;-0.439891;,
    0.619718;0.117894;0.775919;,
    -0.979159;-0.194806;-0.057429;,
    0.562415;0.739537;-0.369831;;
    71;
    3;0,1,2;,
    3;1,0,3;,
    3;4,5,6;,
    3;5,4,7;,
    3;8,0,2;,
    3;9,7,10;,
    3;7,9,5;,
    3;11,12,13;,
    3;14,15,16;,
    3;17,18,19;,
    3;18,17,20;,
    3;21,22,23;,
    3;22,21,8;,
    3;24,25,26;,
    3;25,24,27;,
    3;28,14,29;,
    3;14,28,15;,
    3;30,31,4;,
    3;3,20,17;,
    3;32,22,8;,
    3;22,32,33;,
    3;34,32,35;,
    3;16,15,36;,
    3;21,12,11;,
    3;27,24,31;,
    3;32,2,35;,
    3;37,18,20;,
    3;20,29,37;,
    3;13,27,30;,
    3;27,13,25;,
    3;28,30,38;,
    3;39,32,34;,
    3;32,39,33;,
    3;11,40,3;,
    3;40,11,13;,
    3;3,40,20;,
    3;23,10,24;,
    3;10,23,22;,
    3;33,10,22;,
    3;26,21,23;,
    3;21,26,12;,
    3;28,38,15;,
    3;15,38,6;,
    3;37,16,18;,
    3;8,21,0;,
    3;3,21,11;,
    3;21,3,0;,
    3;2,19,35;,
    3;19,2,1;,
    3;38,30,4;,
    3;38,4,6;,
    3;29,14,37;,
    3;37,14,16;,
    3;40,28,29;,
    3;40,29,20;,
    3;8,2,32;,
    3;28,13,30;,
    3;40,13,28;,
    3;33,9,10;,
    3;33,39,9;,
    3;4,31,7;,
    3;7,31,10;,
    3;23,24,26;,
    3;31,24,10;,
    3;30,27,31;,
    3;26,25,12;,
    3;13,12,25;,
    3;5,36,6;,
    3;15,6,36;,
    3;1,3,17;,
    3;17,19,1;;
   }

   MeshMaterialList  {
    1;
    71;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;
    { PDX21_-_Default }
   }

   MeshTextureCoords  {
    41;
    0.799628;0.548115;,
    -0.272272;0.378402;,
    0.251822;0.444451;,
    1.322937;0.385700;,
    0.847912;0.190036;,
    0.628365;1.156918;,
    0.218298;0.239778;,
    0.670446;0.232472;,
    0.922536;0.409097;,
    0.132633;0.817828;,
    0.563518;-0.181610;,
    0.223141;0.712657;,
    0.551521;0.134256;,
    0.490760;0.921394;,
    0.819765;0.633688;,
    0.817330;0.340231;,
    0.893361;0.040888;,
    -0.063085;0.031769;,
    0.656743;0.634779;,
    0.102637;0.461445;,
    0.530550;0.445472;,
    1.012125;0.221847;,
    1.226330;0.772166;,
    0.255765;0.566289;,
    0.298230;0.902022;,
    0.729545;0.076515;,
    1.034316;0.551946;,
    0.870119;0.550666;,
    0.187877;0.767007;,
    0.684561;0.335271;,
    0.020916;0.299798;,
    0.673314;0.550962;,
    -0.188119;0.825458;,
    0.383508;0.064173;,
    0.167686;0.334871;,
    0.244845;0.272452;,
    0.523934;0.220210;,
    0.382944;0.340560;,
    1.155465;0.026126;,
    0.662677;0.828631;,
    0.188139;1.134422;;
   }
  }
 }
}