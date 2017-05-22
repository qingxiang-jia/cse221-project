#ifndef UNROLLED_MEM_WRITE_H_
#define UNROLLED_MEM_WRITE_H_

#define UNROLLED_MEM_WRITE_HEAD_TAIL \
  {                                  \
    ptr[0] = 1;                      \
    ptr[524287] = 0;                 \
    ptr[8] = 1;                      \
    ptr[524279] = 0;                 \
    ptr[16] = 1;                     \
    ptr[524271] = 0;                 \
    ptr[24] = 1;                     \
    ptr[524263] = 0;                 \
    ptr[32] = 1;                     \
    ptr[524255] = 0;                 \
    ptr[40] = 1;                     \
    ptr[524247] = 0;                 \
    ptr[48] = 1;                     \
    ptr[524239] = 0;                 \
    ptr[56] = 1;                     \
    ptr[524231] = 0;                 \
    ptr[64] = 1;                     \
    ptr[524223] = 0;                 \
    ptr[72] = 1;                     \
    ptr[524215] = 0;                 \
    ptr[80] = 1;                     \
    ptr[524207] = 0;                 \
    ptr[88] = 1;                     \
    ptr[524199] = 0;                 \
    ptr[96] = 1;                     \
    ptr[524191] = 0;                 \
    ptr[104] = 1;                    \
    ptr[524183] = 0;                 \
    ptr[112] = 1;                    \
    ptr[524175] = 0;                 \
    ptr[120] = 1;                    \
    ptr[524167] = 0;                 \
    ptr[128] = 1;                    \
    ptr[524159] = 0;                 \
    ptr[136] = 1;                    \
    ptr[524151] = 0;                 \
    ptr[144] = 1;                    \
    ptr[524143] = 0;                 \
    ptr[152] = 1;                    \
    ptr[524135] = 0;                 \
    ptr[160] = 1;                    \
    ptr[524127] = 0;                 \
    ptr[168] = 1;                    \
    ptr[524119] = 0;                 \
    ptr[176] = 1;                    \
    ptr[524111] = 0;                 \
    ptr[184] = 1;                    \
    ptr[524103] = 0;                 \
    ptr[192] = 1;                    \
    ptr[524095] = 0;                 \
    ptr[200] = 1;                    \
    ptr[524087] = 0;                 \
    ptr[208] = 1;                    \
    ptr[524079] = 0;                 \
    ptr[216] = 1;                    \
    ptr[524071] = 0;                 \
    ptr[224] = 1;                    \
    ptr[524063] = 0;                 \
    ptr[232] = 1;                    \
    ptr[524055] = 0;                 \
    ptr[240] = 1;                    \
    ptr[524047] = 0;                 \
    ptr[248] = 1;                    \
    ptr[524039] = 0;                 \
    ptr[256] = 1;                    \
    ptr[524031] = 0;                 \
    ptr[264] = 1;                    \
    ptr[524023] = 0;                 \
    ptr[272] = 1;                    \
    ptr[524015] = 0;                 \
    ptr[280] = 1;                    \
    ptr[524007] = 0;                 \
    ptr[288] = 1;                    \
    ptr[523999] = 0;                 \
    ptr[296] = 1;                    \
    ptr[523991] = 0;                 \
    ptr[304] = 1;                    \
    ptr[523983] = 0;                 \
    ptr[312] = 1;                    \
    ptr[523975] = 0;                 \
    ptr[320] = 1;                    \
    ptr[523967] = 0;                 \
    ptr[328] = 1;                    \
    ptr[523959] = 0;                 \
    ptr[336] = 1;                    \
    ptr[523951] = 0;                 \
    ptr[344] = 1;                    \
    ptr[523943] = 0;                 \
    ptr[352] = 1;                    \
    ptr[523935] = 0;                 \
    ptr[360] = 1;                    \
    ptr[523927] = 0;                 \
    ptr[368] = 1;                    \
    ptr[523919] = 0;                 \
    ptr[376] = 1;                    \
    ptr[523911] = 0;                 \
    ptr[384] = 1;                    \
    ptr[523903] = 0;                 \
    ptr[392] = 1;                    \
    ptr[523895] = 0;                 \
    ptr[400] = 1;                    \
    ptr[523887] = 0;                 \
    ptr[408] = 1;                    \
    ptr[523879] = 0;                 \
    ptr[416] = 1;                    \
    ptr[523871] = 0;                 \
    ptr[424] = 1;                    \
    ptr[523863] = 0;                 \
    ptr[432] = 1;                    \
    ptr[523855] = 0;                 \
    ptr[440] = 1;                    \
    ptr[523847] = 0;                 \
    ptr[448] = 1;                    \
    ptr[523839] = 0;                 \
    ptr[456] = 1;                    \
    ptr[523831] = 0;                 \
    ptr[464] = 1;                    \
    ptr[523823] = 0;                 \
    ptr[472] = 1;                    \
    ptr[523815] = 0;                 \
    ptr[480] = 1;                    \
    ptr[523807] = 0;                 \
    ptr[488] = 1;                    \
    ptr[523799] = 0;                 \
    ptr[496] = 1;                    \
    ptr[523791] = 0;                 \
    ptr[504] = 1;                    \
    ptr[523783] = 0;                 \
    ptr[512] = 1;                    \
    ptr[523775] = 0;                 \
    ptr[520] = 1;                    \
    ptr[523767] = 0;                 \
    ptr[528] = 1;                    \
    ptr[523759] = 0;                 \
    ptr[536] = 1;                    \
    ptr[523751] = 0;                 \
    ptr[544] = 1;                    \
    ptr[523743] = 0;                 \
    ptr[552] = 1;                    \
    ptr[523735] = 0;                 \
    ptr[560] = 1;                    \
    ptr[523727] = 0;                 \
    ptr[568] = 1;                    \
    ptr[523719] = 0;                 \
    ptr[576] = 1;                    \
    ptr[523711] = 0;                 \
    ptr[584] = 1;                    \
    ptr[523703] = 0;                 \
    ptr[592] = 1;                    \
    ptr[523695] = 0;                 \
    ptr[600] = 1;                    \
    ptr[523687] = 0;                 \
    ptr[608] = 1;                    \
    ptr[523679] = 0;                 \
    ptr[616] = 1;                    \
    ptr[523671] = 0;                 \
    ptr[624] = 1;                    \
    ptr[523663] = 0;                 \
    ptr[632] = 1;                    \
    ptr[523655] = 0;                 \
    ptr[640] = 1;                    \
    ptr[523647] = 0;                 \
    ptr[648] = 1;                    \
    ptr[523639] = 0;                 \
    ptr[656] = 1;                    \
    ptr[523631] = 0;                 \
    ptr[664] = 1;                    \
    ptr[523623] = 0;                 \
    ptr[672] = 1;                    \
    ptr[523615] = 0;                 \
    ptr[680] = 1;                    \
    ptr[523607] = 0;                 \
    ptr[688] = 1;                    \
    ptr[523599] = 0;                 \
    ptr[696] = 1;                    \
    ptr[523591] = 0;                 \
    ptr[704] = 1;                    \
    ptr[523583] = 0;                 \
    ptr[712] = 1;                    \
    ptr[523575] = 0;                 \
    ptr[720] = 1;                    \
    ptr[523567] = 0;                 \
    ptr[728] = 1;                    \
    ptr[523559] = 0;                 \
    ptr[736] = 1;                    \
    ptr[523551] = 0;                 \
    ptr[744] = 1;                    \
    ptr[523543] = 0;                 \
    ptr[752] = 1;                    \
    ptr[523535] = 0;                 \
    ptr[760] = 1;                    \
    ptr[523527] = 0;                 \
    ptr[768] = 1;                    \
    ptr[523519] = 0;                 \
    ptr[776] = 1;                    \
    ptr[523511] = 0;                 \
    ptr[784] = 1;                    \
    ptr[523503] = 0;                 \
    ptr[792] = 1;                    \
    ptr[523495] = 0;                 \
    ptr[800] = 1;                    \
    ptr[523487] = 0;                 \
    ptr[808] = 1;                    \
    ptr[523479] = 0;                 \
    ptr[816] = 1;                    \
    ptr[523471] = 0;                 \
    ptr[824] = 1;                    \
    ptr[523463] = 0;                 \
    ptr[832] = 1;                    \
    ptr[523455] = 0;                 \
    ptr[840] = 1;                    \
    ptr[523447] = 0;                 \
    ptr[848] = 1;                    \
    ptr[523439] = 0;                 \
    ptr[856] = 1;                    \
    ptr[523431] = 0;                 \
    ptr[864] = 1;                    \
    ptr[523423] = 0;                 \
    ptr[872] = 1;                    \
    ptr[523415] = 0;                 \
    ptr[880] = 1;                    \
    ptr[523407] = 0;                 \
    ptr[888] = 1;                    \
    ptr[523399] = 0;                 \
    ptr[896] = 1;                    \
    ptr[523391] = 0;                 \
    ptr[904] = 1;                    \
    ptr[523383] = 0;                 \
    ptr[912] = 1;                    \
    ptr[523375] = 0;                 \
    ptr[920] = 1;                    \
    ptr[523367] = 0;                 \
    ptr[928] = 1;                    \
    ptr[523359] = 0;                 \
    ptr[936] = 1;                    \
    ptr[523351] = 0;                 \
    ptr[944] = 1;                    \
    ptr[523343] = 0;                 \
    ptr[952] = 1;                    \
    ptr[523335] = 0;                 \
    ptr[960] = 1;                    \
    ptr[523327] = 0;                 \
    ptr[968] = 1;                    \
    ptr[523319] = 0;                 \
    ptr[976] = 1;                    \
    ptr[523311] = 0;                 \
    ptr[984] = 1;                    \
    ptr[523303] = 0;                 \
    ptr[992] = 1;                    \
    ptr[523295] = 0;                 \
    ptr[1000] = 1;                   \
    ptr[523287] = 0;                 \
    ptr[1008] = 1;                   \
    ptr[523279] = 0;                 \
    ptr[1016] = 1;                   \
    ptr[523271] = 0;                 \
    ptr[1024] = 1;                   \
    ptr[523263] = 0;                 \
    ptr[1032] = 1;                   \
    ptr[523255] = 0;                 \
    ptr[1040] = 1;                   \
    ptr[523247] = 0;                 \
    ptr[1048] = 1;                   \
    ptr[523239] = 0;                 \
    ptr[1056] = 1;                   \
    ptr[523231] = 0;                 \
    ptr[1064] = 1;                   \
    ptr[523223] = 0;                 \
    ptr[1072] = 1;                   \
    ptr[523215] = 0;                 \
    ptr[1080] = 1;                   \
    ptr[523207] = 0;                 \
    ptr[1088] = 1;                   \
    ptr[523199] = 0;                 \
    ptr[1096] = 1;                   \
    ptr[523191] = 0;                 \
    ptr[1104] = 1;                   \
    ptr[523183] = 0;                 \
    ptr[1112] = 1;                   \
    ptr[523175] = 0;                 \
    ptr[1120] = 1;                   \
    ptr[523167] = 0;                 \
    ptr[1128] = 1;                   \
    ptr[523159] = 0;                 \
    ptr[1136] = 1;                   \
    ptr[523151] = 0;                 \
    ptr[1144] = 1;                   \
    ptr[523143] = 0;                 \
    ptr[1152] = 1;                   \
    ptr[523135] = 0;                 \
    ptr[1160] = 1;                   \
    ptr[523127] = 0;                 \
    ptr[1168] = 1;                   \
    ptr[523119] = 0;                 \
    ptr[1176] = 1;                   \
    ptr[523111] = 0;                 \
    ptr[1184] = 1;                   \
    ptr[523103] = 0;                 \
    ptr[1192] = 1;                   \
    ptr[523095] = 0;                 \
    ptr[1200] = 1;                   \
    ptr[523087] = 0;                 \
    ptr[1208] = 1;                   \
    ptr[523079] = 0;                 \
    ptr[1216] = 1;                   \
    ptr[523071] = 0;                 \
    ptr[1224] = 1;                   \
    ptr[523063] = 0;                 \
    ptr[1232] = 1;                   \
    ptr[523055] = 0;                 \
    ptr[1240] = 1;                   \
    ptr[523047] = 0;                 \
    ptr[1248] = 1;                   \
    ptr[523039] = 0;                 \
    ptr[1256] = 1;                   \
    ptr[523031] = 0;                 \
    ptr[1264] = 1;                   \
    ptr[523023] = 0;                 \
    ptr[1272] = 1;                   \
    ptr[523015] = 0;                 \
    ptr[1280] = 1;                   \
    ptr[523007] = 0;                 \
    ptr[1288] = 1;                   \
    ptr[522999] = 0;                 \
    ptr[1296] = 1;                   \
    ptr[522991] = 0;                 \
    ptr[1304] = 1;                   \
    ptr[522983] = 0;                 \
    ptr[1312] = 1;                   \
    ptr[522975] = 0;                 \
    ptr[1320] = 1;                   \
    ptr[522967] = 0;                 \
    ptr[1328] = 1;                   \
    ptr[522959] = 0;                 \
    ptr[1336] = 1;                   \
    ptr[522951] = 0;                 \
    ptr[1344] = 1;                   \
    ptr[522943] = 0;                 \
    ptr[1352] = 1;                   \
    ptr[522935] = 0;                 \
    ptr[1360] = 1;                   \
    ptr[522927] = 0;                 \
    ptr[1368] = 1;                   \
    ptr[522919] = 0;                 \
    ptr[1376] = 1;                   \
    ptr[522911] = 0;                 \
    ptr[1384] = 1;                   \
    ptr[522903] = 0;                 \
    ptr[1392] = 1;                   \
    ptr[522895] = 0;                 \
    ptr[1400] = 1;                   \
    ptr[522887] = 0;                 \
    ptr[1408] = 1;                   \
    ptr[522879] = 0;                 \
    ptr[1416] = 1;                   \
    ptr[522871] = 0;                 \
    ptr[1424] = 1;                   \
    ptr[522863] = 0;                 \
    ptr[1432] = 1;                   \
    ptr[522855] = 0;                 \
    ptr[1440] = 1;                   \
    ptr[522847] = 0;                 \
    ptr[1448] = 1;                   \
    ptr[522839] = 0;                 \
    ptr[1456] = 1;                   \
    ptr[522831] = 0;                 \
    ptr[1464] = 1;                   \
    ptr[522823] = 0;                 \
    ptr[1472] = 1;                   \
    ptr[522815] = 0;                 \
    ptr[1480] = 1;                   \
    ptr[522807] = 0;                 \
    ptr[1488] = 1;                   \
    ptr[522799] = 0;                 \
    ptr[1496] = 1;                   \
    ptr[522791] = 0;                 \
    ptr[1504] = 1;                   \
    ptr[522783] = 0;                 \
    ptr[1512] = 1;                   \
    ptr[522775] = 0;                 \
    ptr[1520] = 1;                   \
    ptr[522767] = 0;                 \
    ptr[1528] = 1;                   \
    ptr[522759] = 0;                 \
    ptr[1536] = 1;                   \
    ptr[522751] = 0;                 \
    ptr[1544] = 1;                   \
    ptr[522743] = 0;                 \
    ptr[1552] = 1;                   \
    ptr[522735] = 0;                 \
    ptr[1560] = 1;                   \
    ptr[522727] = 0;                 \
    ptr[1568] = 1;                   \
    ptr[522719] = 0;                 \
    ptr[1576] = 1;                   \
    ptr[522711] = 0;                 \
    ptr[1584] = 1;                   \
    ptr[522703] = 0;                 \
    ptr[1592] = 1;                   \
    ptr[522695] = 0;                 \
    ptr[1600] = 1;                   \
    ptr[522687] = 0;                 \
    ptr[1608] = 1;                   \
    ptr[522679] = 0;                 \
    ptr[1616] = 1;                   \
    ptr[522671] = 0;                 \
    ptr[1624] = 1;                   \
    ptr[522663] = 0;                 \
    ptr[1632] = 1;                   \
    ptr[522655] = 0;                 \
    ptr[1640] = 1;                   \
    ptr[522647] = 0;                 \
    ptr[1648] = 1;                   \
    ptr[522639] = 0;                 \
    ptr[1656] = 1;                   \
    ptr[522631] = 0;                 \
    ptr[1664] = 1;                   \
    ptr[522623] = 0;                 \
    ptr[1672] = 1;                   \
    ptr[522615] = 0;                 \
    ptr[1680] = 1;                   \
    ptr[522607] = 0;                 \
    ptr[1688] = 1;                   \
    ptr[522599] = 0;                 \
    ptr[1696] = 1;                   \
    ptr[522591] = 0;                 \
    ptr[1704] = 1;                   \
    ptr[522583] = 0;                 \
    ptr[1712] = 1;                   \
    ptr[522575] = 0;                 \
    ptr[1720] = 1;                   \
    ptr[522567] = 0;                 \
    ptr[1728] = 1;                   \
    ptr[522559] = 0;                 \
    ptr[1736] = 1;                   \
    ptr[522551] = 0;                 \
    ptr[1744] = 1;                   \
    ptr[522543] = 0;                 \
    ptr[1752] = 1;                   \
    ptr[522535] = 0;                 \
    ptr[1760] = 1;                   \
    ptr[522527] = 0;                 \
    ptr[1768] = 1;                   \
    ptr[522519] = 0;                 \
    ptr[1776] = 1;                   \
    ptr[522511] = 0;                 \
    ptr[1784] = 1;                   \
    ptr[522503] = 0;                 \
    ptr[1792] = 1;                   \
    ptr[522495] = 0;                 \
    ptr[1800] = 1;                   \
    ptr[522487] = 0;                 \
    ptr[1808] = 1;                   \
    ptr[522479] = 0;                 \
    ptr[1816] = 1;                   \
    ptr[522471] = 0;                 \
    ptr[1824] = 1;                   \
    ptr[522463] = 0;                 \
    ptr[1832] = 1;                   \
    ptr[522455] = 0;                 \
    ptr[1840] = 1;                   \
    ptr[522447] = 0;                 \
    ptr[1848] = 1;                   \
    ptr[522439] = 0;                 \
    ptr[1856] = 1;                   \
    ptr[522431] = 0;                 \
    ptr[1864] = 1;                   \
    ptr[522423] = 0;                 \
    ptr[1872] = 1;                   \
    ptr[522415] = 0;                 \
    ptr[1880] = 1;                   \
    ptr[522407] = 0;                 \
    ptr[1888] = 1;                   \
    ptr[522399] = 0;                 \
    ptr[1896] = 1;                   \
    ptr[522391] = 0;                 \
    ptr[1904] = 1;                   \
    ptr[522383] = 0;                 \
    ptr[1912] = 1;                   \
    ptr[522375] = 0;                 \
    ptr[1920] = 1;                   \
    ptr[522367] = 0;                 \
    ptr[1928] = 1;                   \
    ptr[522359] = 0;                 \
    ptr[1936] = 1;                   \
    ptr[522351] = 0;                 \
    ptr[1944] = 1;                   \
    ptr[522343] = 0;                 \
    ptr[1952] = 1;                   \
    ptr[522335] = 0;                 \
    ptr[1960] = 1;                   \
    ptr[522327] = 0;                 \
    ptr[1968] = 1;                   \
    ptr[522319] = 0;                 \
    ptr[1976] = 1;                   \
    ptr[522311] = 0;                 \
    ptr[1984] = 1;                   \
    ptr[522303] = 0;                 \
    ptr[1992] = 1;                   \
    ptr[522295] = 0;                 \
    ptr[2000] = 1;                   \
    ptr[522287] = 0;                 \
    ptr[2008] = 1;                   \
    ptr[522279] = 0;                 \
    ptr[2016] = 1;                   \
    ptr[522271] = 0;                 \
    ptr[2024] = 1;                   \
    ptr[522263] = 0;                 \
    ptr[2032] = 1;                   \
    ptr[522255] = 0;                 \
    ptr[2040] = 1;                   \
    ptr[522247] = 0;                 \
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
