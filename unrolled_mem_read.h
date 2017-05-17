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
    d = ptr[8];                     \
    d = ptr[524279];                \
    d = ptr[16];                    \
    d = ptr[524271];                \
    d = ptr[24];                    \
    d = ptr[524263];                \
    d = ptr[32];                    \
    d = ptr[524255];                \
    d = ptr[40];                    \
    d = ptr[524247];                \
    d = ptr[48];                    \
    d = ptr[524239];                \
    d = ptr[56];                    \
    d = ptr[524231];                \
    d = ptr[64];                    \
    d = ptr[524223];                \
    d = ptr[72];                    \
    d = ptr[524215];                \
    d = ptr[80];                    \
    d = ptr[524207];                \
    d = ptr[88];                    \
    d = ptr[524199];                \
    d = ptr[96];                    \
    d = ptr[524191];                \
    d = ptr[104];                   \
    d = ptr[524183];                \
    d = ptr[112];                   \
    d = ptr[524175];                \
    d = ptr[120];                   \
    d = ptr[524167];                \
    d = ptr[128];                   \
    d = ptr[524159];                \
    d = ptr[136];                   \
    d = ptr[524151];                \
    d = ptr[144];                   \
    d = ptr[524143];                \
    d = ptr[152];                   \
    d = ptr[524135];                \
    d = ptr[160];                   \
    d = ptr[524127];                \
    d = ptr[168];                   \
    d = ptr[524119];                \
    d = ptr[176];                   \
    d = ptr[524111];                \
    d = ptr[184];                   \
    d = ptr[524103];                \
    d = ptr[192];                   \
    d = ptr[524095];                \
    d = ptr[200];                   \
    d = ptr[524087];                \
    d = ptr[208];                   \
    d = ptr[524079];                \
    d = ptr[216];                   \
    d = ptr[524071];                \
    d = ptr[224];                   \
    d = ptr[524063];                \
    d = ptr[232];                   \
    d = ptr[524055];                \
    d = ptr[240];                   \
    d = ptr[524047];                \
    d = ptr[248];                   \
    d = ptr[524039];                \
    d = ptr[256];                   \
    d = ptr[524031];                \
    d = ptr[264];                   \
    d = ptr[524023];                \
    d = ptr[272];                   \
    d = ptr[524015];                \
    d = ptr[280];                   \
    d = ptr[524007];                \
    d = ptr[288];                   \
    d = ptr[523999];                \
    d = ptr[296];                   \
    d = ptr[523991];                \
    d = ptr[304];                   \
    d = ptr[523983];                \
    d = ptr[312];                   \
    d = ptr[523975];                \
    d = ptr[320];                   \
    d = ptr[523967];                \
    d = ptr[328];                   \
    d = ptr[523959];                \
    d = ptr[336];                   \
    d = ptr[523951];                \
    d = ptr[344];                   \
    d = ptr[523943];                \
    d = ptr[352];                   \
    d = ptr[523935];                \
    d = ptr[360];                   \
    d = ptr[523927];                \
    d = ptr[368];                   \
    d = ptr[523919];                \
    d = ptr[376];                   \
    d = ptr[523911];                \
    d = ptr[384];                   \
    d = ptr[523903];                \
    d = ptr[392];                   \
    d = ptr[523895];                \
    d = ptr[400];                   \
    d = ptr[523887];                \
    d = ptr[408];                   \
    d = ptr[523879];                \
    d = ptr[416];                   \
    d = ptr[523871];                \
    d = ptr[424];                   \
    d = ptr[523863];                \
    d = ptr[432];                   \
    d = ptr[523855];                \
    d = ptr[440];                   \
    d = ptr[523847];                \
    d = ptr[448];                   \
    d = ptr[523839];                \
    d = ptr[456];                   \
    d = ptr[523831];                \
    d = ptr[464];                   \
    d = ptr[523823];                \
    d = ptr[472];                   \
    d = ptr[523815];                \
    d = ptr[480];                   \
    d = ptr[523807];                \
    d = ptr[488];                   \
    d = ptr[523799];                \
    d = ptr[496];                   \
    d = ptr[523791];                \
    d = ptr[504];                   \
    d = ptr[523783];                \
    d = ptr[512];                   \
    d = ptr[523775];                \
    d = ptr[520];                   \
    d = ptr[523767];                \
    d = ptr[528];                   \
    d = ptr[523759];                \
    d = ptr[536];                   \
    d = ptr[523751];                \
    d = ptr[544];                   \
    d = ptr[523743];                \
    d = ptr[552];                   \
    d = ptr[523735];                \
    d = ptr[560];                   \
    d = ptr[523727];                \
    d = ptr[568];                   \
    d = ptr[523719];                \
    d = ptr[576];                   \
    d = ptr[523711];                \
    d = ptr[584];                   \
    d = ptr[523703];                \
    d = ptr[592];                   \
    d = ptr[523695];                \
    d = ptr[600];                   \
    d = ptr[523687];                \
    d = ptr[608];                   \
    d = ptr[523679];                \
    d = ptr[616];                   \
    d = ptr[523671];                \
    d = ptr[624];                   \
    d = ptr[523663];                \
    d = ptr[632];                   \
    d = ptr[523655];                \
    d = ptr[640];                   \
    d = ptr[523647];                \
    d = ptr[648];                   \
    d = ptr[523639];                \
    d = ptr[656];                   \
    d = ptr[523631];                \
    d = ptr[664];                   \
    d = ptr[523623];                \
    d = ptr[672];                   \
    d = ptr[523615];                \
    d = ptr[680];                   \
    d = ptr[523607];                \
    d = ptr[688];                   \
    d = ptr[523599];                \
    d = ptr[696];                   \
    d = ptr[523591];                \
    d = ptr[704];                   \
    d = ptr[523583];                \
    d = ptr[712];                   \
    d = ptr[523575];                \
    d = ptr[720];                   \
    d = ptr[523567];                \
    d = ptr[728];                   \
    d = ptr[523559];                \
    d = ptr[736];                   \
    d = ptr[523551];                \
    d = ptr[744];                   \
    d = ptr[523543];                \
    d = ptr[752];                   \
    d = ptr[523535];                \
    d = ptr[760];                   \
    d = ptr[523527];                \
    d = ptr[768];                   \
    d = ptr[523519];                \
    d = ptr[776];                   \
    d = ptr[523511];                \
    d = ptr[784];                   \
    d = ptr[523503];                \
    d = ptr[792];                   \
    d = ptr[523495];                \
    d = ptr[800];                   \
    d = ptr[523487];                \
    d = ptr[808];                   \
    d = ptr[523479];                \
    d = ptr[816];                   \
    d = ptr[523471];                \
    d = ptr[824];                   \
    d = ptr[523463];                \
    d = ptr[832];                   \
    d = ptr[523455];                \
    d = ptr[840];                   \
    d = ptr[523447];                \
    d = ptr[848];                   \
    d = ptr[523439];                \
    d = ptr[856];                   \
    d = ptr[523431];                \
    d = ptr[864];                   \
    d = ptr[523423];                \
    d = ptr[872];                   \
    d = ptr[523415];                \
    d = ptr[880];                   \
    d = ptr[523407];                \
    d = ptr[888];                   \
    d = ptr[523399];                \
    d = ptr[896];                   \
    d = ptr[523391];                \
    d = ptr[904];                   \
    d = ptr[523383];                \
    d = ptr[912];                   \
    d = ptr[523375];                \
    d = ptr[920];                   \
    d = ptr[523367];                \
    d = ptr[928];                   \
    d = ptr[523359];                \
    d = ptr[936];                   \
    d = ptr[523351];                \
    d = ptr[944];                   \
    d = ptr[523343];                \
    d = ptr[952];                   \
    d = ptr[523335];                \
    d = ptr[960];                   \
    d = ptr[523327];                \
    d = ptr[968];                   \
    d = ptr[523319];                \
    d = ptr[976];                   \
    d = ptr[523311];                \
    d = ptr[984];                   \
    d = ptr[523303];                \
    d = ptr[992];                   \
    d = ptr[523295];                \
    d = ptr[1000];                  \
    d = ptr[523287];                \
    d = ptr[1008];                  \
    d = ptr[523279];                \
    d = ptr[1016];                  \
    d = ptr[523271];                \
    d = ptr[1024];                  \
    d = ptr[523263];                \
    d = ptr[1032];                  \
    d = ptr[523255];                \
    d = ptr[1040];                  \
    d = ptr[523247];                \
    d = ptr[1048];                  \
    d = ptr[523239];                \
    d = ptr[1056];                  \
    d = ptr[523231];                \
    d = ptr[1064];                  \
    d = ptr[523223];                \
    d = ptr[1072];                  \
    d = ptr[523215];                \
    d = ptr[1080];                  \
    d = ptr[523207];                \
    d = ptr[1088];                  \
    d = ptr[523199];                \
    d = ptr[1096];                  \
    d = ptr[523191];                \
    d = ptr[1104];                  \
    d = ptr[523183];                \
    d = ptr[1112];                  \
    d = ptr[523175];                \
    d = ptr[1120];                  \
    d = ptr[523167];                \
    d = ptr[1128];                  \
    d = ptr[523159];                \
    d = ptr[1136];                  \
    d = ptr[523151];                \
    d = ptr[1144];                  \
    d = ptr[523143];                \
    d = ptr[1152];                  \
    d = ptr[523135];                \
    d = ptr[1160];                  \
    d = ptr[523127];                \
    d = ptr[1168];                  \
    d = ptr[523119];                \
    d = ptr[1176];                  \
    d = ptr[523111];                \
    d = ptr[1184];                  \
    d = ptr[523103];                \
    d = ptr[1192];                  \
    d = ptr[523095];                \
    d = ptr[1200];                  \
    d = ptr[523087];                \
    d = ptr[1208];                  \
    d = ptr[523079];                \
    d = ptr[1216];                  \
    d = ptr[523071];                \
    d = ptr[1224];                  \
    d = ptr[523063];                \
    d = ptr[1232];                  \
    d = ptr[523055];                \
    d = ptr[1240];                  \
    d = ptr[523047];                \
    d = ptr[1248];                  \
    d = ptr[523039];                \
    d = ptr[1256];                  \
    d = ptr[523031];                \
    d = ptr[1264];                  \
    d = ptr[523023];                \
    d = ptr[1272];                  \
    d = ptr[523015];                \
    d = ptr[1280];                  \
    d = ptr[523007];                \
    d = ptr[1288];                  \
    d = ptr[522999];                \
    d = ptr[1296];                  \
    d = ptr[522991];                \
    d = ptr[1304];                  \
    d = ptr[522983];                \
    d = ptr[1312];                  \
    d = ptr[522975];                \
    d = ptr[1320];                  \
    d = ptr[522967];                \
    d = ptr[1328];                  \
    d = ptr[522959];                \
    d = ptr[1336];                  \
    d = ptr[522951];                \
    d = ptr[1344];                  \
    d = ptr[522943];                \
    d = ptr[1352];                  \
    d = ptr[522935];                \
    d = ptr[1360];                  \
    d = ptr[522927];                \
    d = ptr[1368];                  \
    d = ptr[522919];                \
    d = ptr[1376];                  \
    d = ptr[522911];                \
    d = ptr[1384];                  \
    d = ptr[522903];                \
    d = ptr[1392];                  \
    d = ptr[522895];                \
    d = ptr[1400];                  \
    d = ptr[522887];                \
    d = ptr[1408];                  \
    d = ptr[522879];                \
    d = ptr[1416];                  \
    d = ptr[522871];                \
    d = ptr[1424];                  \
    d = ptr[522863];                \
    d = ptr[1432];                  \
    d = ptr[522855];                \
    d = ptr[1440];                  \
    d = ptr[522847];                \
    d = ptr[1448];                  \
    d = ptr[522839];                \
    d = ptr[1456];                  \
    d = ptr[522831];                \
    d = ptr[1464];                  \
    d = ptr[522823];                \
    d = ptr[1472];                  \
    d = ptr[522815];                \
    d = ptr[1480];                  \
    d = ptr[522807];                \
    d = ptr[1488];                  \
    d = ptr[522799];                \
    d = ptr[1496];                  \
    d = ptr[522791];                \
    d = ptr[1504];                  \
    d = ptr[522783];                \
    d = ptr[1512];                  \
    d = ptr[522775];                \
    d = ptr[1520];                  \
    d = ptr[522767];                \
    d = ptr[1528];                  \
    d = ptr[522759];                \
    d = ptr[1536];                  \
    d = ptr[522751];                \
    d = ptr[1544];                  \
    d = ptr[522743];                \
    d = ptr[1552];                  \
    d = ptr[522735];                \
    d = ptr[1560];                  \
    d = ptr[522727];                \
    d = ptr[1568];                  \
    d = ptr[522719];                \
    d = ptr[1576];                  \
    d = ptr[522711];                \
    d = ptr[1584];                  \
    d = ptr[522703];                \
    d = ptr[1592];                  \
    d = ptr[522695];                \
    d = ptr[1600];                  \
    d = ptr[522687];                \
    d = ptr[1608];                  \
    d = ptr[522679];                \
    d = ptr[1616];                  \
    d = ptr[522671];                \
    d = ptr[1624];                  \
    d = ptr[522663];                \
    d = ptr[1632];                  \
    d = ptr[522655];                \
    d = ptr[1640];                  \
    d = ptr[522647];                \
    d = ptr[1648];                  \
    d = ptr[522639];                \
    d = ptr[1656];                  \
    d = ptr[522631];                \
    d = ptr[1664];                  \
    d = ptr[522623];                \
    d = ptr[1672];                  \
    d = ptr[522615];                \
    d = ptr[1680];                  \
    d = ptr[522607];                \
    d = ptr[1688];                  \
    d = ptr[522599];                \
    d = ptr[1696];                  \
    d = ptr[522591];                \
    d = ptr[1704];                  \
    d = ptr[522583];                \
    d = ptr[1712];                  \
    d = ptr[522575];                \
    d = ptr[1720];                  \
    d = ptr[522567];                \
    d = ptr[1728];                  \
    d = ptr[522559];                \
    d = ptr[1736];                  \
    d = ptr[522551];                \
    d = ptr[1744];                  \
    d = ptr[522543];                \
    d = ptr[1752];                  \
    d = ptr[522535];                \
    d = ptr[1760];                  \
    d = ptr[522527];                \
    d = ptr[1768];                  \
    d = ptr[522519];                \
    d = ptr[1776];                  \
    d = ptr[522511];                \
    d = ptr[1784];                  \
    d = ptr[522503];                \
    d = ptr[1792];                  \
    d = ptr[522495];                \
    d = ptr[1800];                  \
    d = ptr[522487];                \
    d = ptr[1808];                  \
    d = ptr[522479];                \
    d = ptr[1816];                  \
    d = ptr[522471];                \
    d = ptr[1824];                  \
    d = ptr[522463];                \
    d = ptr[1832];                  \
    d = ptr[522455];                \
    d = ptr[1840];                  \
    d = ptr[522447];                \
    d = ptr[1848];                  \
    d = ptr[522439];                \
    d = ptr[1856];                  \
    d = ptr[522431];                \
    d = ptr[1864];                  \
    d = ptr[522423];                \
    d = ptr[1872];                  \
    d = ptr[522415];                \
    d = ptr[1880];                  \
    d = ptr[522407];                \
    d = ptr[1888];                  \
    d = ptr[522399];                \
    d = ptr[1896];                  \
    d = ptr[522391];                \
    d = ptr[1904];                  \
    d = ptr[522383];                \
    d = ptr[1912];                  \
    d = ptr[522375];                \
    d = ptr[1920];                  \
    d = ptr[522367];                \
    d = ptr[1928];                  \
    d = ptr[522359];                \
    d = ptr[1936];                  \
    d = ptr[522351];                \
    d = ptr[1944];                  \
    d = ptr[522343];                \
    d = ptr[1952];                  \
    d = ptr[522335];                \
    d = ptr[1960];                  \
    d = ptr[522327];                \
    d = ptr[1968];                  \
    d = ptr[522319];                \
    d = ptr[1976];                  \
    d = ptr[522311];                \
    d = ptr[1984];                  \
    d = ptr[522303];                \
    d = ptr[1992];                  \
    d = ptr[522295];                \
    d = ptr[2000];                  \
    d = ptr[522287];                \
    d = ptr[2008];                  \
    d = ptr[522279];                \
    d = ptr[2016];                  \
    d = ptr[522271];                \
    d = ptr[2024];                  \
    d = ptr[522263];                \
    d = ptr[2032];                  \
    d = ptr[522255];                \
    d = ptr[2040];                  \
    d = ptr[522247];                \
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