#ifndef UNROLLED_MEM_READ_H_
#define UNROLLED_MEM_READ_H_

/**
>>> 524288/16
32768
>>> 32768/16
2048
>>> 2048/16
128
>>> 128/16
8
>>>
*/

#define UNROLLED_MEM_READ_HEAD_TAIL \
  {                                 \
    d = ptr[0];                     \
    d = ptr[524287];                \
    d = ptr[1];                     \
    d = ptr[524286];                \
    d = ptr[2];                     \
    d = ptr[524285];                \
    d = ptr[3];                     \
    d = ptr[524284];                \
    d = ptr[4];                     \
    d = ptr[524283];                \
    d = ptr[5];                     \
    d = ptr[524282];                \
    d = ptr[6];                     \
    d = ptr[524281];                \
    d = ptr[7];                     \
    d = ptr[524280];                \
    d = ptr[8];                     \
    d = ptr[524279];                \
    d = ptr[9];                     \
    d = ptr[524278];                \
    d = ptr[10];                    \
    d = ptr[524277];                \
    d = ptr[11];                    \
    d = ptr[524276];                \
    d = ptr[12];                    \
    d = ptr[524275];                \
    d = ptr[13];                    \
    d = ptr[524274];                \
    d = ptr[14];                    \
    d = ptr[524273];                \
    d = ptr[15];                    \
    d = ptr[524272];                \
    d = ptr[16];                    \
    d = ptr[524271];                \
    d = ptr[17];                    \
    d = ptr[524270];                \
    d = ptr[18];                    \
    d = ptr[524269];                \
    d = ptr[19];                    \
    d = ptr[524268];                \
    d = ptr[20];                    \
    d = ptr[524267];                \
    d = ptr[21];                    \
    d = ptr[524266];                \
    d = ptr[22];                    \
    d = ptr[524265];                \
    d = ptr[23];                    \
    d = ptr[524264];                \
    d = ptr[24];                    \
    d = ptr[524263];                \
    d = ptr[25];                    \
    d = ptr[524262];                \
    d = ptr[26];                    \
    d = ptr[524261];                \
    d = ptr[27];                    \
    d = ptr[524260];                \
    d = ptr[28];                    \
    d = ptr[524259];                \
    d = ptr[29];                    \
    d = ptr[524258];                \
    d = ptr[30];                    \
    d = ptr[524257];                \
    d = ptr[31];                    \
    d = ptr[524256];                \
    d = ptr[32];                    \
    d = ptr[524255];                \
    d = ptr[33];                    \
    d = ptr[524254];                \
    d = ptr[34];                    \
    d = ptr[524253];                \
    d = ptr[35];                    \
    d = ptr[524252];                \
    d = ptr[36];                    \
    d = ptr[524251];                \
    d = ptr[37];                    \
    d = ptr[524250];                \
    d = ptr[38];                    \
    d = ptr[524249];                \
    d = ptr[39];                    \
    d = ptr[524248];                \
    d = ptr[40];                    \
    d = ptr[524247];                \
    d = ptr[41];                    \
    d = ptr[524246];                \
    d = ptr[42];                    \
    d = ptr[524245];                \
    d = ptr[43];                    \
    d = ptr[524244];                \
    d = ptr[44];                    \
    d = ptr[524243];                \
    d = ptr[45];                    \
    d = ptr[524242];                \
    d = ptr[46];                    \
    d = ptr[524241];                \
    d = ptr[47];                    \
    d = ptr[524240];                \
    d = ptr[48];                    \
    d = ptr[524239];                \
    d = ptr[49];                    \
    d = ptr[524238];                \
    d = ptr[50];                    \
    d = ptr[524237];                \
    d = ptr[51];                    \
    d = ptr[524236];                \
    d = ptr[52];                    \
    d = ptr[524235];                \
    d = ptr[53];                    \
    d = ptr[524234];                \
    d = ptr[54];                    \
    d = ptr[524233];                \
    d = ptr[55];                    \
    d = ptr[524232];                \
    d = ptr[56];                    \
    d = ptr[524231];                \
    d = ptr[57];                    \
    d = ptr[524230];                \
    d = ptr[58];                    \
    d = ptr[524229];                \
    d = ptr[59];                    \
    d = ptr[524228];                \
    d = ptr[60];                    \
    d = ptr[524227];                \
    d = ptr[61];                    \
    d = ptr[524226];                \
    d = ptr[62];                    \
    d = ptr[524225];                \
    d = ptr[63];                    \
    d = ptr[524224];                \
    d = ptr[64];                    \
    d = ptr[524223];                \
    d = ptr[65];                    \
    d = ptr[524222];                \
    d = ptr[66];                    \
    d = ptr[524221];                \
    d = ptr[67];                    \
    d = ptr[524220];                \
    d = ptr[68];                    \
    d = ptr[524219];                \
    d = ptr[69];                    \
    d = ptr[524218];                \
    d = ptr[70];                    \
    d = ptr[524217];                \
    d = ptr[71];                    \
    d = ptr[524216];                \
    d = ptr[72];                    \
    d = ptr[524215];                \
    d = ptr[73];                    \
    d = ptr[524214];                \
    d = ptr[74];                    \
    d = ptr[524213];                \
    d = ptr[75];                    \
    d = ptr[524212];                \
    d = ptr[76];                    \
    d = ptr[524211];                \
    d = ptr[77];                    \
    d = ptr[524210];                \
    d = ptr[78];                    \
    d = ptr[524209];                \
    d = ptr[79];                    \
    d = ptr[524208];                \
    d = ptr[80];                    \
    d = ptr[524207];                \
    d = ptr[81];                    \
    d = ptr[524206];                \
    d = ptr[82];                    \
    d = ptr[524205];                \
    d = ptr[83];                    \
    d = ptr[524204];                \
    d = ptr[84];                    \
    d = ptr[524203];                \
    d = ptr[85];                    \
    d = ptr[524202];                \
    d = ptr[86];                    \
    d = ptr[524201];                \
    d = ptr[87];                    \
    d = ptr[524200];                \
    d = ptr[88];                    \
    d = ptr[524199];                \
    d = ptr[89];                    \
    d = ptr[524198];                \
    d = ptr[90];                    \
    d = ptr[524197];                \
    d = ptr[91];                    \
    d = ptr[524196];                \
    d = ptr[92];                    \
    d = ptr[524195];                \
    d = ptr[93];                    \
    d = ptr[524194];                \
    d = ptr[94];                    \
    d = ptr[524193];                \
    d = ptr[95];                    \
    d = ptr[524192];                \
    d = ptr[96];                    \
    d = ptr[524191];                \
    d = ptr[97];                    \
    d = ptr[524190];                \
    d = ptr[98];                    \
    d = ptr[524189];                \
    d = ptr[99];                    \
    d = ptr[524188];                \
    d = ptr[100];                   \
    d = ptr[524187];                \
    d = ptr[101];                   \
    d = ptr[524186];                \
    d = ptr[102];                   \
    d = ptr[524185];                \
    d = ptr[103];                   \
    d = ptr[524184];                \
    d = ptr[104];                   \
    d = ptr[524183];                \
    d = ptr[105];                   \
    d = ptr[524182];                \
    d = ptr[106];                   \
    d = ptr[524181];                \
    d = ptr[107];                   \
    d = ptr[524180];                \
    d = ptr[108];                   \
    d = ptr[524179];                \
    d = ptr[109];                   \
    d = ptr[524178];                \
    d = ptr[110];                   \
    d = ptr[524177];                \
    d = ptr[111];                   \
    d = ptr[524176];                \
    d = ptr[112];                   \
    d = ptr[524175];                \
    d = ptr[113];                   \
    d = ptr[524174];                \
    d = ptr[114];                   \
    d = ptr[524173];                \
    d = ptr[115];                   \
    d = ptr[524172];                \
    d = ptr[116];                   \
    d = ptr[524171];                \
    d = ptr[117];                   \
    d = ptr[524170];                \
    d = ptr[118];                   \
    d = ptr[524169];                \
    d = ptr[119];                   \
    d = ptr[524168];                \
    d = ptr[120];                   \
    d = ptr[524167];                \
    d = ptr[121];                   \
    d = ptr[524166];                \
    d = ptr[122];                   \
    d = ptr[524165];                \
    d = ptr[123];                   \
    d = ptr[524164];                \
    d = ptr[124];                   \
    d = ptr[524163];                \
    d = ptr[125];                   \
    d = ptr[524162];                \
    d = ptr[126];                   \
    d = ptr[524161];                \
    d = ptr[127];                   \
    d = ptr[524160];                \
    d = ptr[128];                   \
    d = ptr[524159];                \
    d = ptr[129];                   \
    d = ptr[524158];                \
    d = ptr[130];                   \
    d = ptr[524157];                \
    d = ptr[131];                   \
    d = ptr[524156];                \
    d = ptr[132];                   \
    d = ptr[524155];                \
    d = ptr[133];                   \
    d = ptr[524154];                \
    d = ptr[134];                   \
    d = ptr[524153];                \
    d = ptr[135];                   \
    d = ptr[524152];                \
    d = ptr[136];                   \
    d = ptr[524151];                \
    d = ptr[137];                   \
    d = ptr[524150];                \
    d = ptr[138];                   \
    d = ptr[524149];                \
    d = ptr[139];                   \
    d = ptr[524148];                \
    d = ptr[140];                   \
    d = ptr[524147];                \
    d = ptr[141];                   \
    d = ptr[524146];                \
    d = ptr[142];                   \
    d = ptr[524145];                \
    d = ptr[143];                   \
    d = ptr[524144];                \
    d = ptr[144];                   \
    d = ptr[524143];                \
    d = ptr[145];                   \
    d = ptr[524142];                \
    d = ptr[146];                   \
    d = ptr[524141];                \
    d = ptr[147];                   \
    d = ptr[524140];                \
    d = ptr[148];                   \
    d = ptr[524139];                \
    d = ptr[149];                   \
    d = ptr[524138];                \
    d = ptr[150];                   \
    d = ptr[524137];                \
    d = ptr[151];                   \
    d = ptr[524136];                \
    d = ptr[152];                   \
    d = ptr[524135];                \
    d = ptr[153];                   \
    d = ptr[524134];                \
    d = ptr[154];                   \
    d = ptr[524133];                \
    d = ptr[155];                   \
    d = ptr[524132];                \
    d = ptr[156];                   \
    d = ptr[524131];                \
    d = ptr[157];                   \
    d = ptr[524130];                \
    d = ptr[158];                   \
    d = ptr[524129];                \
    d = ptr[159];                   \
    d = ptr[524128];                \
    d = ptr[160];                   \
    d = ptr[524127];                \
    d = ptr[161];                   \
    d = ptr[524126];                \
    d = ptr[162];                   \
    d = ptr[524125];                \
    d = ptr[163];                   \
    d = ptr[524124];                \
    d = ptr[164];                   \
    d = ptr[524123];                \
    d = ptr[165];                   \
    d = ptr[524122];                \
    d = ptr[166];                   \
    d = ptr[524121];                \
    d = ptr[167];                   \
    d = ptr[524120];                \
    d = ptr[168];                   \
    d = ptr[524119];                \
    d = ptr[169];                   \
    d = ptr[524118];                \
    d = ptr[170];                   \
    d = ptr[524117];                \
    d = ptr[171];                   \
    d = ptr[524116];                \
    d = ptr[172];                   \
    d = ptr[524115];                \
    d = ptr[173];                   \
    d = ptr[524114];                \
    d = ptr[174];                   \
    d = ptr[524113];                \
    d = ptr[175];                   \
    d = ptr[524112];                \
    d = ptr[176];                   \
    d = ptr[524111];                \
    d = ptr[177];                   \
    d = ptr[524110];                \
    d = ptr[178];                   \
    d = ptr[524109];                \
    d = ptr[179];                   \
    d = ptr[524108];                \
    d = ptr[180];                   \
    d = ptr[524107];                \
    d = ptr[181];                   \
    d = ptr[524106];                \
    d = ptr[182];                   \
    d = ptr[524105];                \
    d = ptr[183];                   \
    d = ptr[524104];                \
    d = ptr[184];                   \
    d = ptr[524103];                \
    d = ptr[185];                   \
    d = ptr[524102];                \
    d = ptr[186];                   \
    d = ptr[524101];                \
    d = ptr[187];                   \
    d = ptr[524100];                \
    d = ptr[188];                   \
    d = ptr[524099];                \
    d = ptr[189];                   \
    d = ptr[524098];                \
    d = ptr[190];                   \
    d = ptr[524097];                \
    d = ptr[191];                   \
    d = ptr[524096];                \
    d = ptr[192];                   \
    d = ptr[524095];                \
    d = ptr[193];                   \
    d = ptr[524094];                \
    d = ptr[194];                   \
    d = ptr[524093];                \
    d = ptr[195];                   \
    d = ptr[524092];                \
    d = ptr[196];                   \
    d = ptr[524091];                \
    d = ptr[197];                   \
    d = ptr[524090];                \
    d = ptr[198];                   \
    d = ptr[524089];                \
    d = ptr[199];                   \
    d = ptr[524088];                \
    d = ptr[200];                   \
    d = ptr[524087];                \
    d = ptr[201];                   \
    d = ptr[524086];                \
    d = ptr[202];                   \
    d = ptr[524085];                \
    d = ptr[203];                   \
    d = ptr[524084];                \
    d = ptr[204];                   \
    d = ptr[524083];                \
    d = ptr[205];                   \
    d = ptr[524082];                \
    d = ptr[206];                   \
    d = ptr[524081];                \
    d = ptr[207];                   \
    d = ptr[524080];                \
    d = ptr[208];                   \
    d = ptr[524079];                \
    d = ptr[209];                   \
    d = ptr[524078];                \
    d = ptr[210];                   \
    d = ptr[524077];                \
    d = ptr[211];                   \
    d = ptr[524076];                \
    d = ptr[212];                   \
    d = ptr[524075];                \
    d = ptr[213];                   \
    d = ptr[524074];                \
    d = ptr[214];                   \
    d = ptr[524073];                \
    d = ptr[215];                   \
    d = ptr[524072];                \
    d = ptr[216];                   \
    d = ptr[524071];                \
    d = ptr[217];                   \
    d = ptr[524070];                \
    d = ptr[218];                   \
    d = ptr[524069];                \
    d = ptr[219];                   \
    d = ptr[524068];                \
    d = ptr[220];                   \
    d = ptr[524067];                \
    d = ptr[221];                   \
    d = ptr[524066];                \
    d = ptr[222];                   \
    d = ptr[524065];                \
    d = ptr[223];                   \
    d = ptr[524064];                \
    d = ptr[224];                   \
    d = ptr[524063];                \
    d = ptr[225];                   \
    d = ptr[524062];                \
    d = ptr[226];                   \
    d = ptr[524061];                \
    d = ptr[227];                   \
    d = ptr[524060];                \
    d = ptr[228];                   \
    d = ptr[524059];                \
    d = ptr[229];                   \
    d = ptr[524058];                \
    d = ptr[230];                   \
    d = ptr[524057];                \
    d = ptr[231];                   \
    d = ptr[524056];                \
    d = ptr[232];                   \
    d = ptr[524055];                \
    d = ptr[233];                   \
    d = ptr[524054];                \
    d = ptr[234];                   \
    d = ptr[524053];                \
    d = ptr[235];                   \
    d = ptr[524052];                \
    d = ptr[236];                   \
    d = ptr[524051];                \
    d = ptr[237];                   \
    d = ptr[524050];                \
    d = ptr[238];                   \
    d = ptr[524049];                \
    d = ptr[239];                   \
    d = ptr[524048];                \
    d = ptr[240];                   \
    d = ptr[524047];                \
    d = ptr[241];                   \
    d = ptr[524046];                \
    d = ptr[242];                   \
    d = ptr[524045];                \
    d = ptr[243];                   \
    d = ptr[524044];                \
    d = ptr[244];                   \
    d = ptr[524043];                \
    d = ptr[245];                   \
    d = ptr[524042];                \
    d = ptr[246];                   \
    d = ptr[524041];                \
    d = ptr[247];                   \
    d = ptr[524040];                \
    d = ptr[248];                   \
    d = ptr[524039];                \
    d = ptr[249];                   \
    d = ptr[524038];                \
    d = ptr[250];                   \
    d = ptr[524037];                \
    d = ptr[251];                   \
    d = ptr[524036];                \
    d = ptr[252];                   \
    d = ptr[524035];                \
    d = ptr[253];                   \
    d = ptr[524034];                \
    d = ptr[254];                   \
    d = ptr[524033];                \
    d = ptr[255];                   \
    d = ptr[524032];                \
  }

#define UNROLLED_MEM_READ_LINE \
  {                            \
    d = ptr[i++];              \
  }

#define UNROLLED_MEM_READ_LINE8 \
  {                             \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
    UNROLLED_MEM_READ_LINE      \
  }

#define UNROLLED_MEM_READ_LINE128 \
  {                               \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
    UNROLLED_MEM_READ_LINE8       \
  }

#define UNROLLED_MEM_READ_LINE2048 \
  {                                \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
    UNROLLED_MEM_READ_LINE128      \
  }

#define UNROLLED_MEM_READ_LINE32768 \
  {                                 \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
    UNROLLED_MEM_READ_LINE2048      \
  }

#define UNROLLED_MEM_READ_LINE524288 \
  {                                  \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
    UNROLLED_MEM_READ_LINE32768      \
  }

#endif
