#ifndef UNROLLED_MEM_WRITE_H_
#define UNROLLED_MEM_WRITE_H_

#define UNROLLED_MEM_WRITE_HEAD_TAIL \
  {                                  \
    ptr[0] = 1;                      \
    ptr[524287] = 0;                 \
    ptr[1] = 1;                      \
    ptr[524286] = 0;                 \
    ptr[2] = 1;                      \
    ptr[524285] = 0;                 \
    ptr[3] = 1;                      \
    ptr[524284] = 0;                 \
    ptr[4] = 1;                      \
    ptr[524283] = 0;                 \
    ptr[5] = 1;                      \
    ptr[524282] = 0;                 \
    ptr[6] = 1;                      \
    ptr[524281] = 0;                 \
    ptr[7] = 1;                      \
    ptr[524280] = 0;                 \
    ptr[8] = 1;                      \
    ptr[524279] = 0;                 \
    ptr[9] = 1;                      \
    ptr[524278] = 0;                 \
    ptr[10] = 1;                     \
    ptr[524277] = 0;                 \
    ptr[11] = 1;                     \
    ptr[524276] = 0;                 \
    ptr[12] = 1;                     \
    ptr[524275] = 0;                 \
    ptr[13] = 1;                     \
    ptr[524274] = 0;                 \
    ptr[14] = 1;                     \
    ptr[524273] = 0;                 \
    ptr[15] = 1;                     \
    ptr[524272] = 0;                 \
    ptr[16] = 1;                     \
    ptr[524271] = 0;                 \
    ptr[17] = 1;                     \
    ptr[524270] = 0;                 \
    ptr[18] = 1;                     \
    ptr[524269] = 0;                 \
    ptr[19] = 1;                     \
    ptr[524268] = 0;                 \
    ptr[20] = 1;                     \
    ptr[524267] = 0;                 \
    ptr[21] = 1;                     \
    ptr[524266] = 0;                 \
    ptr[22] = 1;                     \
    ptr[524265] = 0;                 \
    ptr[23] = 1;                     \
    ptr[524264] = 0;                 \
    ptr[24] = 1;                     \
    ptr[524263] = 0;                 \
    ptr[25] = 1;                     \
    ptr[524262] = 0;                 \
    ptr[26] = 1;                     \
    ptr[524261] = 0;                 \
    ptr[27] = 1;                     \
    ptr[524260] = 0;                 \
    ptr[28] = 1;                     \
    ptr[524259] = 0;                 \
    ptr[29] = 1;                     \
    ptr[524258] = 0;                 \
    ptr[30] = 1;                     \
    ptr[524257] = 0;                 \
    ptr[31] = 1;                     \
    ptr[524256] = 0;                 \
    ptr[32] = 1;                     \
    ptr[524255] = 0;                 \
    ptr[33] = 1;                     \
    ptr[524254] = 0;                 \
    ptr[34] = 1;                     \
    ptr[524253] = 0;                 \
    ptr[35] = 1;                     \
    ptr[524252] = 0;                 \
    ptr[36] = 1;                     \
    ptr[524251] = 0;                 \
    ptr[37] = 1;                     \
    ptr[524250] = 0;                 \
    ptr[38] = 1;                     \
    ptr[524249] = 0;                 \
    ptr[39] = 1;                     \
    ptr[524248] = 0;                 \
    ptr[40] = 1;                     \
    ptr[524247] = 0;                 \
    ptr[41] = 1;                     \
    ptr[524246] = 0;                 \
    ptr[42] = 1;                     \
    ptr[524245] = 0;                 \
    ptr[43] = 1;                     \
    ptr[524244] = 0;                 \
    ptr[44] = 1;                     \
    ptr[524243] = 0;                 \
    ptr[45] = 1;                     \
    ptr[524242] = 0;                 \
    ptr[46] = 1;                     \
    ptr[524241] = 0;                 \
    ptr[47] = 1;                     \
    ptr[524240] = 0;                 \
    ptr[48] = 1;                     \
    ptr[524239] = 0;                 \
    ptr[49] = 1;                     \
    ptr[524238] = 0;                 \
    ptr[50] = 1;                     \
    ptr[524237] = 0;                 \
    ptr[51] = 1;                     \
    ptr[524236] = 0;                 \
    ptr[52] = 1;                     \
    ptr[524235] = 0;                 \
    ptr[53] = 1;                     \
    ptr[524234] = 0;                 \
    ptr[54] = 1;                     \
    ptr[524233] = 0;                 \
    ptr[55] = 1;                     \
    ptr[524232] = 0;                 \
    ptr[56] = 1;                     \
    ptr[524231] = 0;                 \
    ptr[57] = 1;                     \
    ptr[524230] = 0;                 \
    ptr[58] = 1;                     \
    ptr[524229] = 0;                 \
    ptr[59] = 1;                     \
    ptr[524228] = 0;                 \
    ptr[60] = 1;                     \
    ptr[524227] = 0;                 \
    ptr[61] = 1;                     \
    ptr[524226] = 0;                 \
    ptr[62] = 1;                     \
    ptr[524225] = 0;                 \
    ptr[63] = 1;                     \
    ptr[524224] = 0;                 \
    ptr[64] = 1;                     \
    ptr[524223] = 0;                 \
    ptr[65] = 1;                     \
    ptr[524222] = 0;                 \
    ptr[66] = 1;                     \
    ptr[524221] = 0;                 \
    ptr[67] = 1;                     \
    ptr[524220] = 0;                 \
    ptr[68] = 1;                     \
    ptr[524219] = 0;                 \
    ptr[69] = 1;                     \
    ptr[524218] = 0;                 \
    ptr[70] = 1;                     \
    ptr[524217] = 0;                 \
    ptr[71] = 1;                     \
    ptr[524216] = 0;                 \
    ptr[72] = 1;                     \
    ptr[524215] = 0;                 \
    ptr[73] = 1;                     \
    ptr[524214] = 0;                 \
    ptr[74] = 1;                     \
    ptr[524213] = 0;                 \
    ptr[75] = 1;                     \
    ptr[524212] = 0;                 \
    ptr[76] = 1;                     \
    ptr[524211] = 0;                 \
    ptr[77] = 1;                     \
    ptr[524210] = 0;                 \
    ptr[78] = 1;                     \
    ptr[524209] = 0;                 \
    ptr[79] = 1;                     \
    ptr[524208] = 0;                 \
    ptr[80] = 1;                     \
    ptr[524207] = 0;                 \
    ptr[81] = 1;                     \
    ptr[524206] = 0;                 \
    ptr[82] = 1;                     \
    ptr[524205] = 0;                 \
    ptr[83] = 1;                     \
    ptr[524204] = 0;                 \
    ptr[84] = 1;                     \
    ptr[524203] = 0;                 \
    ptr[85] = 1;                     \
    ptr[524202] = 0;                 \
    ptr[86] = 1;                     \
    ptr[524201] = 0;                 \
    ptr[87] = 1;                     \
    ptr[524200] = 0;                 \
    ptr[88] = 1;                     \
    ptr[524199] = 0;                 \
    ptr[89] = 1;                     \
    ptr[524198] = 0;                 \
    ptr[90] = 1;                     \
    ptr[524197] = 0;                 \
    ptr[91] = 1;                     \
    ptr[524196] = 0;                 \
    ptr[92] = 1;                     \
    ptr[524195] = 0;                 \
    ptr[93] = 1;                     \
    ptr[524194] = 0;                 \
    ptr[94] = 1;                     \
    ptr[524193] = 0;                 \
    ptr[95] = 1;                     \
    ptr[524192] = 0;                 \
    ptr[96] = 1;                     \
    ptr[524191] = 0;                 \
    ptr[97] = 1;                     \
    ptr[524190] = 0;                 \
    ptr[98] = 1;                     \
    ptr[524189] = 0;                 \
    ptr[99] = 1;                     \
    ptr[524188] = 0;                 \
    ptr[100] = 1;                    \
    ptr[524187] = 0;                 \
    ptr[101] = 1;                    \
    ptr[524186] = 0;                 \
    ptr[102] = 1;                    \
    ptr[524185] = 0;                 \
    ptr[103] = 1;                    \
    ptr[524184] = 0;                 \
    ptr[104] = 1;                    \
    ptr[524183] = 0;                 \
    ptr[105] = 1;                    \
    ptr[524182] = 0;                 \
    ptr[106] = 1;                    \
    ptr[524181] = 0;                 \
    ptr[107] = 1;                    \
    ptr[524180] = 0;                 \
    ptr[108] = 1;                    \
    ptr[524179] = 0;                 \
    ptr[109] = 1;                    \
    ptr[524178] = 0;                 \
    ptr[110] = 1;                    \
    ptr[524177] = 0;                 \
    ptr[111] = 1;                    \
    ptr[524176] = 0;                 \
    ptr[112] = 1;                    \
    ptr[524175] = 0;                 \
    ptr[113] = 1;                    \
    ptr[524174] = 0;                 \
    ptr[114] = 1;                    \
    ptr[524173] = 0;                 \
    ptr[115] = 1;                    \
    ptr[524172] = 0;                 \
    ptr[116] = 1;                    \
    ptr[524171] = 0;                 \
    ptr[117] = 1;                    \
    ptr[524170] = 0;                 \
    ptr[118] = 1;                    \
    ptr[524169] = 0;                 \
    ptr[119] = 1;                    \
    ptr[524168] = 0;                 \
    ptr[120] = 1;                    \
    ptr[524167] = 0;                 \
    ptr[121] = 1;                    \
    ptr[524166] = 0;                 \
    ptr[122] = 1;                    \
    ptr[524165] = 0;                 \
    ptr[123] = 1;                    \
    ptr[524164] = 0;                 \
    ptr[124] = 1;                    \
    ptr[524163] = 0;                 \
    ptr[125] = 1;                    \
    ptr[524162] = 0;                 \
    ptr[126] = 1;                    \
    ptr[524161] = 0;                 \
    ptr[127] = 1;                    \
    ptr[524160] = 0;                 \
    ptr[128] = 1;                    \
    ptr[524159] = 0;                 \
    ptr[129] = 1;                    \
    ptr[524158] = 0;                 \
    ptr[130] = 1;                    \
    ptr[524157] = 0;                 \
    ptr[131] = 1;                    \
    ptr[524156] = 0;                 \
    ptr[132] = 1;                    \
    ptr[524155] = 0;                 \
    ptr[133] = 1;                    \
    ptr[524154] = 0;                 \
    ptr[134] = 1;                    \
    ptr[524153] = 0;                 \
    ptr[135] = 1;                    \
    ptr[524152] = 0;                 \
    ptr[136] = 1;                    \
    ptr[524151] = 0;                 \
    ptr[137] = 1;                    \
    ptr[524150] = 0;                 \
    ptr[138] = 1;                    \
    ptr[524149] = 0;                 \
    ptr[139] = 1;                    \
    ptr[524148] = 0;                 \
    ptr[140] = 1;                    \
    ptr[524147] = 0;                 \
    ptr[141] = 1;                    \
    ptr[524146] = 0;                 \
    ptr[142] = 1;                    \
    ptr[524145] = 0;                 \
    ptr[143] = 1;                    \
    ptr[524144] = 0;                 \
    ptr[144] = 1;                    \
    ptr[524143] = 0;                 \
    ptr[145] = 1;                    \
    ptr[524142] = 0;                 \
    ptr[146] = 1;                    \
    ptr[524141] = 0;                 \
    ptr[147] = 1;                    \
    ptr[524140] = 0;                 \
    ptr[148] = 1;                    \
    ptr[524139] = 0;                 \
    ptr[149] = 1;                    \
    ptr[524138] = 0;                 \
    ptr[150] = 1;                    \
    ptr[524137] = 0;                 \
    ptr[151] = 1;                    \
    ptr[524136] = 0;                 \
    ptr[152] = 1;                    \
    ptr[524135] = 0;                 \
    ptr[153] = 1;                    \
    ptr[524134] = 0;                 \
    ptr[154] = 1;                    \
    ptr[524133] = 0;                 \
    ptr[155] = 1;                    \
    ptr[524132] = 0;                 \
    ptr[156] = 1;                    \
    ptr[524131] = 0;                 \
    ptr[157] = 1;                    \
    ptr[524130] = 0;                 \
    ptr[158] = 1;                    \
    ptr[524129] = 0;                 \
    ptr[159] = 1;                    \
    ptr[524128] = 0;                 \
    ptr[160] = 1;                    \
    ptr[524127] = 0;                 \
    ptr[161] = 1;                    \
    ptr[524126] = 0;                 \
    ptr[162] = 1;                    \
    ptr[524125] = 0;                 \
    ptr[163] = 1;                    \
    ptr[524124] = 0;                 \
    ptr[164] = 1;                    \
    ptr[524123] = 0;                 \
    ptr[165] = 1;                    \
    ptr[524122] = 0;                 \
    ptr[166] = 1;                    \
    ptr[524121] = 0;                 \
    ptr[167] = 1;                    \
    ptr[524120] = 0;                 \
    ptr[168] = 1;                    \
    ptr[524119] = 0;                 \
    ptr[169] = 1;                    \
    ptr[524118] = 0;                 \
    ptr[170] = 1;                    \
    ptr[524117] = 0;                 \
    ptr[171] = 1;                    \
    ptr[524116] = 0;                 \
    ptr[172] = 1;                    \
    ptr[524115] = 0;                 \
    ptr[173] = 1;                    \
    ptr[524114] = 0;                 \
    ptr[174] = 1;                    \
    ptr[524113] = 0;                 \
    ptr[175] = 1;                    \
    ptr[524112] = 0;                 \
    ptr[176] = 1;                    \
    ptr[524111] = 0;                 \
    ptr[177] = 1;                    \
    ptr[524110] = 0;                 \
    ptr[178] = 1;                    \
    ptr[524109] = 0;                 \
    ptr[179] = 1;                    \
    ptr[524108] = 0;                 \
    ptr[180] = 1;                    \
    ptr[524107] = 0;                 \
    ptr[181] = 1;                    \
    ptr[524106] = 0;                 \
    ptr[182] = 1;                    \
    ptr[524105] = 0;                 \
    ptr[183] = 1;                    \
    ptr[524104] = 0;                 \
    ptr[184] = 1;                    \
    ptr[524103] = 0;                 \
    ptr[185] = 1;                    \
    ptr[524102] = 0;                 \
    ptr[186] = 1;                    \
    ptr[524101] = 0;                 \
    ptr[187] = 1;                    \
    ptr[524100] = 0;                 \
    ptr[188] = 1;                    \
    ptr[524099] = 0;                 \
    ptr[189] = 1;                    \
    ptr[524098] = 0;                 \
    ptr[190] = 1;                    \
    ptr[524097] = 0;                 \
    ptr[191] = 1;                    \
    ptr[524096] = 0;                 \
    ptr[192] = 1;                    \
    ptr[524095] = 0;                 \
    ptr[193] = 1;                    \
    ptr[524094] = 0;                 \
    ptr[194] = 1;                    \
    ptr[524093] = 0;                 \
    ptr[195] = 1;                    \
    ptr[524092] = 0;                 \
    ptr[196] = 1;                    \
    ptr[524091] = 0;                 \
    ptr[197] = 1;                    \
    ptr[524090] = 0;                 \
    ptr[198] = 1;                    \
    ptr[524089] = 0;                 \
    ptr[199] = 1;                    \
    ptr[524088] = 0;                 \
    ptr[200] = 1;                    \
    ptr[524087] = 0;                 \
    ptr[201] = 1;                    \
    ptr[524086] = 0;                 \
    ptr[202] = 1;                    \
    ptr[524085] = 0;                 \
    ptr[203] = 1;                    \
    ptr[524084] = 0;                 \
    ptr[204] = 1;                    \
    ptr[524083] = 0;                 \
    ptr[205] = 1;                    \
    ptr[524082] = 0;                 \
    ptr[206] = 1;                    \
    ptr[524081] = 0;                 \
    ptr[207] = 1;                    \
    ptr[524080] = 0;                 \
    ptr[208] = 1;                    \
    ptr[524079] = 0;                 \
    ptr[209] = 1;                    \
    ptr[524078] = 0;                 \
    ptr[210] = 1;                    \
    ptr[524077] = 0;                 \
    ptr[211] = 1;                    \
    ptr[524076] = 0;                 \
    ptr[212] = 1;                    \
    ptr[524075] = 0;                 \
    ptr[213] = 1;                    \
    ptr[524074] = 0;                 \
    ptr[214] = 1;                    \
    ptr[524073] = 0;                 \
    ptr[215] = 1;                    \
    ptr[524072] = 0;                 \
    ptr[216] = 1;                    \
    ptr[524071] = 0;                 \
    ptr[217] = 1;                    \
    ptr[524070] = 0;                 \
    ptr[218] = 1;                    \
    ptr[524069] = 0;                 \
    ptr[219] = 1;                    \
    ptr[524068] = 0;                 \
    ptr[220] = 1;                    \
    ptr[524067] = 0;                 \
    ptr[221] = 1;                    \
    ptr[524066] = 0;                 \
    ptr[222] = 1;                    \
    ptr[524065] = 0;                 \
    ptr[223] = 1;                    \
    ptr[524064] = 0;                 \
    ptr[224] = 1;                    \
    ptr[524063] = 0;                 \
    ptr[225] = 1;                    \
    ptr[524062] = 0;                 \
    ptr[226] = 1;                    \
    ptr[524061] = 0;                 \
    ptr[227] = 1;                    \
    ptr[524060] = 0;                 \
    ptr[228] = 1;                    \
    ptr[524059] = 0;                 \
    ptr[229] = 1;                    \
    ptr[524058] = 0;                 \
    ptr[230] = 1;                    \
    ptr[524057] = 0;                 \
    ptr[231] = 1;                    \
    ptr[524056] = 0;                 \
    ptr[232] = 1;                    \
    ptr[524055] = 0;                 \
    ptr[233] = 1;                    \
    ptr[524054] = 0;                 \
    ptr[234] = 1;                    \
    ptr[524053] = 0;                 \
    ptr[235] = 1;                    \
    ptr[524052] = 0;                 \
    ptr[236] = 1;                    \
    ptr[524051] = 0;                 \
    ptr[237] = 1;                    \
    ptr[524050] = 0;                 \
    ptr[238] = 1;                    \
    ptr[524049] = 0;                 \
    ptr[239] = 1;                    \
    ptr[524048] = 0;                 \
    ptr[240] = 1;                    \
    ptr[524047] = 0;                 \
    ptr[241] = 1;                    \
    ptr[524046] = 0;                 \
    ptr[242] = 1;                    \
    ptr[524045] = 0;                 \
    ptr[243] = 1;                    \
    ptr[524044] = 0;                 \
    ptr[244] = 1;                    \
    ptr[524043] = 0;                 \
    ptr[245] = 1;                    \
    ptr[524042] = 0;                 \
    ptr[246] = 1;                    \
    ptr[524041] = 0;                 \
    ptr[247] = 1;                    \
    ptr[524040] = 0;                 \
    ptr[248] = 1;                    \
    ptr[524039] = 0;                 \
    ptr[249] = 1;                    \
    ptr[524038] = 0;                 \
    ptr[250] = 1;                    \
    ptr[524037] = 0;                 \
    ptr[251] = 1;                    \
    ptr[524036] = 0;                 \
    ptr[252] = 1;                    \
    ptr[524035] = 0;                 \
    ptr[253] = 1;                    \
    ptr[524034] = 0;                 \
    ptr[254] = 1;                    \
    ptr[524033] = 0;                 \
    ptr[255] = 1;                    \
    ptr[524032] = 0;                 \
  }

#define UNROLLED_MEM_WRITE_LINE \
  {                             \
    *ptr = 7;                   \
    ptr++;                      \
  }

#define UNROLLED_MEM_WRITE_LINE8 \
  {                              \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
    UNROLLED_MEM_WRITE_LINE      \
  }

#define UNROLLED_MEM_WRITE_LINE128 \
  {                                \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
    UNROLLED_MEM_WRITE_LINE8       \
  }

#define UNROLLED_MEM_WRITE_LINE2048 \
  {                                 \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
    UNROLLED_MEM_WRITE_LINE128      \
  }

#define UNROLLED_MEM_WRITE_LINE32768 \
  {                                  \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
    UNROLLED_MEM_WRITE_LINE2048      \
  }

#define UNROLLED_MEM_WRITE_LINE524288 \
  {                                   \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
    UNROLLED_MEM_WRITE_LINE32768      \
  }

#endif
