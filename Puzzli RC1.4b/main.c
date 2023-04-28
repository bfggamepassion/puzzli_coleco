#include <string.h>
#include <coleco.h>
#include <getput1.h>


/* VDP table addresses */
#define chrtab  0x1800 /* écran en linéaire */
#define chrgen  0x0000 /* table des caractères */
#define coltab  0x2000 /* couleur des caractères */
#define sprtab  0x3800 /* sprite_pattern_table */
#define sprgen  0x1b00 /* sprite_attribute_table */
#define buffer  0x1c00 /* buffer screen 2 */

#define VIDE    0
#define F1      1 /* FISH1 */
#define F2      2
#define F3      3
#define F4      4
#define F5 	    5
#define F6      6
#define F7      7
#define F8      8
#define F1_2      21 /* FISH1 */
#define F2_2      22
#define F3_2      23
#define F4_2      24
#define F5_2 	 25
#define F6_2      26
#define F7_2      27
#define F8_2      28
#define FB  	9
#define BOAT	10
#define ERASE_3x1 11
#define ERASE_3x2 12
#define ZAP	13
#define ETOILE 102

#define CONTINUE 1

#define MAXX	32
#define MAXY	24

#define SENS1 1
#define SENS2 2

#define DIFF_NORMAL	 30
#define	DIFF_HARD	 130
#define DIFF_TRAINING 	 1 // Valeur du niveau de démarrage

#define DIFF_END_NORMAL	  67+1 //niveau + 1
#define DIFF_END_HARD	  168
#define DIFF_END_TRAINING 19 // Valeur du niveau de fin + 1

#define TYPE1	1
#define TYPE2	2
#define TYPE3	3

#define DTRAINING 0
#define DEASY 1
#define DNORMAL 2
#define DHARD 3

#define SPACE 24

#define OK          0
#define NOK         1

static const byte bleu_fonce_font[8]= { 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41 };
static const byte bleu_clair_inverse_font[8]= {0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15};

/*extern const byte fond[];*/
extern const byte charset[];
extern const byte charset_color[];
extern const byte intro[];

extern const byte NAMERLE[];
extern const byte PATTERNRLE[];
extern const byte COLORRLE[];

extern const byte NAMERLEmenu[];
extern const byte PATTERNRLEmenu[];
extern const byte COLORRLEmenu[];

extern const char txt_level[7];
extern const char txt_menu1[15];
extern const char txt_menu2[27];
extern const char txt_menu3[27];
extern const char txt_menu4[27];
extern const char txt_menu5[27];
extern const char txt_menu6[22];
extern const char txt_menu7[22];
extern const char txt_menu8[22];
extern const char txt_congrat[19];
extern const char txt_gameover[10];
extern const char txt_finalscore[12];
extern const char txt_continue[29];
extern const char txt_tryscore[29];

extern const char level1_map[6][9];
extern const char level2_map[6][9];
extern const char level3_map[6][9];
extern const char level4_map[6][9];
extern const char level5_map[6][9];
extern const char level6_map[6][9];
extern const char level7_map[6][9];
extern const char level8_map[6][9];
extern const char level9_map[6][9];
extern const char level10_map[6][9];
extern const char level11_map[6][9];
extern const char level12_map[6][9];
extern const char level13_map[6][9];
extern const char level14_map[6][9];
extern const char level15_map[6][9];
extern const char level16_map[6][9];
extern const char level17_map[6][9];
extern const char level18_map[6][9];

extern const char normal001_map[6][9];
extern const char normal002_map[6][9];
extern const char normal003_map[6][9];
extern const char normal004_map[6][9];
extern const char normal005_map[6][9];
extern const char normal006_map[6][9];
extern const char normal007_map[6][9];
extern const char normal008_map[6][9];    
extern const char normal01_map[6][9];
extern const char normal02_map[6][9];
extern const char normal03_map[6][9];
extern const char normal04_map[6][9];
extern const char normal05_map[6][9];
extern const char normal06_map[6][9];
extern const char normal07_map[6][9];
extern const char normal08_map[6][9];
extern const char normal09_map[6][9];
extern const char normal10_map[6][9];
extern const char normal11_map[6][9];
extern const char normal12_map[6][9];
extern const char normal13_map[6][9];
extern const char normal14_map[6][9];
extern const char normal15_map[6][9];
extern const char normal16_map[6][9];
extern const char normal17_map[6][9];
extern const char normal18_map[6][9];
extern const char normal19_map[6][9];
extern const char normal20_map[6][9];
extern const char normal21_map[6][9];
extern const char normal22_map[6][9];
extern const char normal23_map[6][9];
extern const char normal24_map[6][9];
extern const char normal25_map[6][9];
extern const char normal26_map[6][9];
extern const char normal27_map[6][9];
extern const char normal28_map[6][9];
extern const char normal29_map[6][9];
extern const char normal30_map[6][9];

extern const sound_t snd_table[] ;

const byte frm[19][8] = {
           {2,2+8,2+16,2+1,2+1+8,2+1+16},	//0
           {4,4+8,4+16,4+1,4+1+8,4+1+16},
           {122,122+8,122+16,122+1,122+1+8,122+1+16},
           {96,96+8,96+16,96+1,96+1+8,96+1+16},
           {180,180+8,180+16,180+1,180+1+8,180+1+16},           
           {0,8,16,1,9,17},
           {6,6+8,6+16,6+1,6+1+8,6+1+16},           
           {156,156+8,156+16,156+1,156+1+8,156+1+16}, //7           
           {128,128+8,128+16,128+1,128+1+8,128+1+16}, //8
           {204,204,204,204,204,204},
           {152,152+8,152+16,152+1,152+1+8,152+1+16},
           {154,154+8,154+16,154+1,154+1+8,154+1+16},
           {176,176+8,176+16,176+1,176+1+8,176+1+16},
           {178,178+8,178+16,178+1,178+1+8,178+1+16},
           {182,182+8,182+16,182+1,182+1+8,182+1+16},
           {126,126+8,126+16,126+1,126+1+8,126+1+16},            
           {124,124+8,124+16,124+1,124+1+8,124+1+16},
           {158,158+8,158+16,158+1,158+1+8,158+1+16},
           {27,27,27,27,27,27}
};

const byte perso[5][30] = {
	{204,204,204,204,204,204,
	 204,204,204,204,204,204,
	 204,204,204,204,204,204,
	 204,204,204,204,204,204,
	 204,204,204,204,204,204},
	{204,204,204, 99,107,115,
	 204,204,204,100,108,116,
	 204,204,204,101,109,117,
	 204,204,204,239,247,255,
	  98,106,106,106,106,114},
	{204,204, 99,107,115,204,
	 204,204,100,108,116,204,
	 204,204,101,109,117,204,
	 204,204,239,247,255,204,
	  98,106,106,106,106,114},
	{204, 99,107,115,204,204,
	 204,100,108,116,204,204,
	 204,101,109,117,204,204,
	 204,239,247,255,204,204,
	  98,106,106,106,106,114},
	{ 99,107,115,204,204,204,
	 100,108,116,204,204,204,
	 101,109,117,204,204,204,
	 239,247,255,204,204,204,
	  98,106,106,106,106,114}
};
           
                                 


typedef struct
{
	char sens;
        char x,y; // position x,y dans l'écran
        char oldx,oldy; // ancienne position
        char col;  // Position x dans la grille
        char oldcol;
        char flotaison; // Ligne de flotaison (graphiquement, le joueur sera au dessus)
        char current_fish; // Poisson courant des les mains
        char stock_fish;   // Poisson en stock
        char vitflot;	// Vitesse de baisse de flotaison.
        char compteurlance; //Nombre de lance avant de baisser la flotaison
        unsigned tombe_auto; // Vitesse du tombage auto
        
        byte level; 	// Level courant 
        char next_level;  // A t'il le droit de passer au next level ?                
        unsigned plyscore_combo;
} player_fisher;

unsigned plyscore; // Je le sors pour tester si le bug vient de la

player_fisher player;

char laMer_poisson[6][9];
char laMer_work[6][9];

char toucheRelachee;
char renderLaMer;
char renderPlayer;
char renderplyscore;
char renderMovePlayerLeft;
char renderMovePlayerRight;
char renderBaisseFlotaison;
char renderSwitch;
char renderFond;
char renderPutFish;

char vague;

char gameOver;

byte difficulte;
byte startLevel;
byte endLevel;
char config;

unsigned timer1;
unsigned timer2;

char flag1;

void nmi(void) {}

void show_buffer()
{
     byte buf[64];
     int y;
     unsigned offsety;
     
     offsety = 0;
     
     for (y=0;y<12;y++)
     {
         get_vram(buffer+offsety,buf,64);
         put_vram(chrtab+offsety,buf,64);
         offsety+=64;
     }
     
}

void paint_number_bleu_fonce(void) {
	put_vram_pattern (coltab+48*8,bleu_fonce_font,8,10);
	put_vram_pattern ((coltab+48*8)+2048,bleu_fonce_font,8,10);
	put_vram_pattern ((coltab+48*8)+2048+2048,bleu_fonce_font,8,10);
}
void paint_number_bleu_clair_inverse(void) 
{
	put_vram_pattern (coltab+48*8,bleu_clair_inverse_font,8,10);
	put_vram_pattern ((coltab+48*8)+2048,bleu_clair_inverse_font,8,10);
	put_vram_pattern ((coltab+48*8)+2048+2048,bleu_clair_inverse_font,8,10);
}

void show_plyscore()
{
     print_at(26,15,str(player.level-startLevel+1));
     put_char(23+1,15,232);put_char(24+1,15,233);put_char(25+1,15,232);put_char(26+1,15,229);put_char(27+1,15,230);
     //print_at(23,15,txt_level);
     print_at(24+1,13,str(plyscore));
}

void rec(char px,char py,char h,char l,char contour,char centre)
{
     char x,y;
     for (x=px;x<px+l;x++) put_char(x,py,contour);
     for (x=px;x<px+l;x++) put_char(x,py+h,contour);
     for (y=py;y<py+h;y++) put_char(px,y,contour);
     for (y=py;y<py+h;y++) put_char(px+l,y,contour);
     put_char(px+l,py+h,contour);
     
     for (x=px+1;x<px+l;x++)
         for (y=py+1;y<py+h;y++)
              put_char(x,y,centre);
}

void render_menu()
{
     char m,tr,r,localx,localy;
    m=0; // Position dans le menu
    tr=OK; // Touche relachée
    r=0; //
    
     disable_nmi();
	screen_off();
	fill_vram(0,0,0x4000);

   	load_patternrle(PATTERNRLEmenu);
   	duplicate_pattern();
  	rle2vram(COLORRLEmenu,coltab);
   	rle2vram(COLORRLEmenu,coltab+2048);
   	rle2vram(COLORRLEmenu,coltab+4096);
     	
    rle2vram(NAMERLEmenu,buffer);
    
	show_buffer();
    screen_on();
 	
 	while(1)
 	{
            enable_nmi();
            if ((joypad_1 & DOWN) && (tr==OK))
            { 
               if (m<7) m++;
               tr=NOK;
            }
            if ((joypad_1 & UP) && (tr==OK)) 
            {
               if (m>0) m--;
               tr=NOK;
            }
            if (!(joypad_1 & DOWN) && !(joypad_1 & UP)) tr=OK;
            
            if (joypad_1 & FIRE1)
            {
                         if (m==0) break;
                         if (m==1) {difficulte = DEASY;startLevel = DIFF_NORMAL;endLevel = DIFF_END_NORMAL;}
                         if (m==2) {difficulte = DNORMAL;startLevel = DIFF_NORMAL;endLevel = DIFF_END_NORMAL;}
                         if (m==3) {difficulte = DHARD;startLevel = DIFF_NORMAL;endLevel = DIFF_END_NORMAL;}
                         if (m==4) {difficulte = DTRAINING;startLevel = DIFF_TRAINING;endLevel = DIFF_END_TRAINING;}
                         if (m==5) config=TYPE1;
                         if (m==6) config=TYPE2;
                         if (m==7) config=TYPE3;             
            }
            
            delay(1);
            disable_nmi(); 
     rle2vram(NAMERLEmenu,buffer);
		
	print_at(14,7,txt_menu1);
	print_at(14,10,txt_menu2);
	print_at(14,11,txt_menu3);
	print_at(14,12,txt_menu4);
    print_at(14,13,txt_menu5);		
	print_at(14,15,txt_menu6);
	print_at(14,16,txt_menu7);
	print_at(14,17,txt_menu8);  
            // Rendering du menu
            if (m==0) put_char(12,7,249);
            if (m==1) put_char(12,10,249);
            if (m==2) put_char(12,11,249);
            if (m==3) put_char(12,12,249);
            if (m==4) put_char(12,13,249);
            if (m==5) put_char(12,15,249);
            if (m==6) put_char(12,16,249);
            if (m==7) put_char(12,17,249);
            if (difficulte==DEASY)  put_char(13,10,248); 
            if (difficulte==DNORMAL)  put_char(13,11,248);
            if (difficulte==DHARD)  put_char(13,12,248);
            if (difficulte==DTRAINING)  put_char(13,13,248);
            if (config==TYPE1)  put_char(13,15,248);
            if (config==TYPE2)  put_char(13,16,248);
            if (config==TYPE3)  put_char(13,17,248);
            show_buffer();
    }
 	

    disable_nmi();
	screen_off();
	fill_vram(0,0,0x4000);

   	load_patternrle(charset);
   	duplicate_pattern();
  	rle2vram(charset_color,coltab);
   	rle2vram(charset_color,coltab+2048);
   	rle2vram(charset_color,coltab+4096);
     	
	for (localx=0;localx<MAXX;localx++)
	 for (localy=0;localy<MAXY;localy++)
		put_char(localx,localy,SPACE); 
   show_buffer();
   screen_on();
   enable_nmi();
   delay(1);
}

char is_last_line_full(void)
{
	int x;
	for (x=0;x<6;x++)
		if (laMer_poisson[x][8]==0) return NOK;
		
	return OK;
}


char next_fish_random(void)  
{
	char x,y,fish;
	char tab[10];
	char index,trouve,idx;
	byte bet;
	int maxp;
	
	idx = 0;
	
	for (index=0;index < 10;index ++)
		tab[index] = 255;
	maxp = 9;
	if (difficulte == DTRAINING) maxp = 9;
	if (difficulte == DEASY) {maxp = player.flotaison+2;}
	if (difficulte == DNORMAL) {maxp = player.flotaison+4;}
	if (difficulte == DHARD) maxp = 9;
	if (maxp>9) maxp=9;
	
	for (x=0;x<6;x++)		/* On parcours la mer */
		for (y=player.flotaison;y<maxp;y++)
		{
			fish = laMer_poisson[x][y]; /* On récupère le poisson dans la mer */
			trouve = 0;
			for (index=0;index<10;index++)
			{
				if (tab[index] == fish) /* Existe t'il déja dans le panier ? */
					trouve =1;
			}
			if (trouve==0) /* Si non, on le met dans le panier. */
			{
				/* On ne me que les poissons dans le panier */
				if ((fish!=0) && (fish!=FB)) /* Si ce n'est pas du vide ou une bulle */
				{
					tab[idx] = fish;
					idx++;
				}
			}
		}
		
		/* sécurité plantage */	
		if (idx==0) return F1;
				
		if ((idx-1) == 0) return tab[0];				
		bet = rnd_byte(0,idx-1); 
		return tab[bet];	
}

char check_next_level(void)
{
	int x;
	
	for (x=0;x<6;x++)
		if (laMer_poisson[x][player.flotaison]!=0) return NOK;
		
	player.next_level = 1;
	return OK;
}

void put_char3x3(char x,char y,char c)
{
     		put_char(x,y,c);put_char(x+1,y,c+8);put_char(x+2,y,c+16);
		put_char(x,y+1,c+1);put_char(x+1,y+1,c+1+8);put_char(x+2,y+1,c+1+16);
}

void put_char2x2(char x,char y,char c)
{
     		put_char(x,y,c);put_char(x+1,y,c+8);
		put_char(x,y+1,c+1);put_char(x+1,y+1,c+1+8);
}

void show_object(char x,char y,byte obj_number)
{
	if (obj_number==VIDE)
	{
		put_char(x,y,26);put_char(x+1,y,26);put_char(x+2,y,26);
		put_char(x,y+1,26);put_char(x+1,y+1,26);put_char(x+2,y+1,26);
	} else 
	if (obj_number==F1) put_frame0(&frm[0],x,y,3,2);//put_char3x3(x,y,0);
    else 
	if (obj_number==F2) put_frame0(&frm[1],x,y,3,2);//put_char3x3(x,y,2);
	else 
	if (obj_number==F3) put_frame0(&frm[2],x,y,3,2);//put_char3x3(x,y,4);
	else 
	if (obj_number==F4) put_frame0(&frm[3],x,y,3,2);//put_char3x3(x,y,6);
	else 
	if (obj_number==F5) put_frame0(&frm[4],x,y,3,2);//put_char3x3(x,y,96);
	else 
	if (obj_number==F6) put_frame0(&frm[5],x,y,3,2);//put_char3x3(x,y,122);
	else 
	if (obj_number==F7) put_frame0(&frm[6],x,y,3,2);//put_char3x3(x,y,124);
	else 
	if (obj_number==F8) put_frame0(&frm[7],x,y,3,2);//put_char3x3(x,y,180);
	else 
	if (obj_number==FB) put_frame0(&frm[8],x,y,3,2);//put_char3x3(x,y,128);
	else 
	if (obj_number==BOAT)
	{	
		put_char(x,y,98);put_char(x+1,y,106);put_char(x+2,y,114);
            	if (timer2==2) {put_char(x+1,y,201);}
            	else
            	if (timer2==3) {put_char(x+1,y,202);}
            	else
            	if (timer2==4) {put_char(x+1,y,202);} 
            	
	} else 
	if (obj_number==ERASE_3x1)
	{
		
		put_char(x,y,204);put_char(x+1,y,204);put_char(x+2,y,204);
		
	} else 
	if (obj_number==ERASE_3x2)
	{
		
		put_frame0(&frm[9],x,y,3,2);
		
	} else 
	if (obj_number==ZAP)
	{
		put_frame0(&frm[18],x,y,3,2);
//		put_char(x,y,27);put_char(x+1,y,27);put_char(x+2,y,27);
//		put_char(x,y+1,27);put_char(x+1,y+1,27);put_char(x+2,y+1,27);
		
	} else 
	if (obj_number==99)
	{
		
		put_char(x,y,30);put_char(x+1,y,30);put_char(x+2,y,30);
		put_char(x,y+1,30);put_char(x+1,y+1,30);put_char(x+2,y+1,30);
		
	} else 
	if (obj_number==100)
	{
		
		put_char(x,y,31);put_char(x+1,y,31);put_char(x+2,y,31);
		
	} else 
	if (obj_number==F1_2) put_frame0(&frm[10],x,y,3,2);//put_char3x3(x,y,126);
	else 
	if (obj_number==F2_2) put_frame0(&frm[11],x,y,3,2);//put_char3x3(x,y,152);
	else 
	if (obj_number==F3_2) put_frame0(&frm[12],x,y,3,2);//put_char3x3(x,y,154);
	else 
	if (obj_number==F4_2) put_frame0(&frm[13],x,y,3,2);//put_char3x3(x,y,156);
	else 
	if (obj_number==F5_2) put_frame0(&frm[14],x,y,3,2);//put_char3x3(x,y,158);
	else 
	if (obj_number==F6_2) put_frame0(&frm[15],x,y,3,2);//put_char3x3(x,y,176);
	else 
	if (obj_number==F7_2) put_frame0(&frm[16],x,y,3,2);//put_char3x3(x,y,178);
	else 
	if (obj_number==F8_2) put_frame0(&frm[17],x,y,3,2);//put_char3x3(x,y,182);
	else 
	if (obj_number==ETOILE)  put_char2x2(x,y,102);
}

void render_switch(void)
{
	show_object(25,4,player.stock_fish+20);
}

void switch_fish(void)
{
	char tmp;
	tmp = player.current_fish;
	player.current_fish = player.stock_fish;
	player.stock_fish = tmp;
}


/* Baisse le niveau de flotaison */
/* Retourne 0 sur GameOver 1 sinon */
int baisse_flotaison()
{
    char x,y;
 
    /* On vérifie que c'est possible */
    for (x=0;x<9;x++)
    {
        if (laMer_poisson[x][8]!=0) 
        	{
        		gameOver = 1; 
        		return NOK;
        	}
    }
    
    /* On baisse la ligne de flotaison du joueur */
    player.flotaison++;
    player.oldy = player.y;	
    player.y += 2;	
    
    /* On efface toute la ligne ou était le joueur */   
    
    
    for (x=0;x<18;x++)
    {
       	     put_char(3+x,player.oldy,204);
       	     put_char(3+x,player.oldy+1,204);
       	     put_char(3+x,player.oldy+2,204);
       	     put_char(3+x,player.oldy+3,204);
       	     put_char(3+x,player.oldy+4,204);       	     
       	     put_char(3+x,player.oldy+5,204); 
       	     put_char(3+x,player.oldy+6,204); 
       	           	     
    }
    
    /*for (x=0;x<18;x+=2)
    {
    	put_char(3+x,player.oldy+5,207);
    	put_char(3+x+1,player.oldy+5,215);
    }*/
    
    delay(5);
    
    /* On décale tout le reste vers le bas */
    for (x=0;x<9;x++)
        for (y=8;y>=player.flotaison;y--)
            laMer_poisson[x][y] = laMer_poisson[x][y-1];
    
        /* On efface la ligne de flotaison précédente */
    for (x=0;x<9;x++)
        laMer_poisson[x][player.flotaison-1] = 0;
        
    player.compteurlance = 0;
    
    return OK;
}



void init_player(void)
{
	player.sens = SENS1;
	player.col = 3;
	player.oldcol=3;
	player.flotaison = 0;
	player.x = 3+player.col+player.col+player.col;
	player.y = 0+player.flotaison+player.flotaison;	
	player.oldx = player.x;
	player.oldy = player.y;	
	player.stock_fish = next_fish_random();
	player.current_fish = next_fish_random();    
    	player.vitflot = 7;	
	player.compteurlance = 0;
	player.level = startLevel;
	player.next_level = 0;
	player.plyscore_combo = 1;
    plyscore = 0;
}

void reinit_player(void)
{
	player.sens=SENS1;
	player.col = 3;
	player.oldcol=3;
	player.flotaison = 0;
	player.x = 3+player.col+player.col+player.col;
	player.y = 0+player.flotaison+player.flotaison;	
	player.oldx = player.x;
	player.oldy = player.y;	
	player.stock_fish = next_fish_random();
	player.current_fish = next_fish_random();	
	/*player.vitflot = 7;	*/
	player.compteurlance = 0;
	player.next_level = 0;
	player.plyscore_combo = 1;
}

void render_player(char fish)
{
        char i,xwarn;
        xwarn=player.x;
		if (player.sens==SENS1)
		{
 			if (player.x<15) 
 			{ 	
	 			put_frame0(&perso[1],player.x,player.y,6,5); 	 			 			 			
 				put_frame0(&perso[0],player.oldx,player.y,6,5); 					
 				put_frame0(&perso[1],player.x,player.y,6,5); 	 			 			 			
 				if (fish==OK) show_object(player.x,player.y+2,player.current_fish+20);
 			}	
 			else 
 			{
 				put_frame0(&perso[0],12,player.y,6,5);
 				//put_frame0(&perso[0],15,player.oldy,6,5);
 				put_frame0(&perso[player.x-14],15,player.y,6,5);
 				if (fish==OK) show_object(player.x,player.y+2,player.current_fish+20);
 			} 		
 		}
 		else
 		{
 			if (player.x>2) 
 			{ 	
	 			put_frame0(&perso[4],player.x,player.y,6,5); 
	 			if (player.oldx<16)	 			 			 			
 					put_frame0(&perso[0],player.oldx,player.y,6,5);
 				else
 					put_frame0(&perso[0],15,player.y,6,5);
 				put_frame0(&perso[4],player.x,player.y,6,5); 	 			 			 			
 				if (fish==OK) show_object(player.x+3,player.y+2,player.current_fish+20);
 			}	
 			else 
 			{
 				put_frame0(&perso[0],12,player.y,6,5);
 				//put_frame0(&perso[0],15,player.oldy,6,5);
 				put_frame0(&perso[player.x+1],3,player.y,6,5);
 				if (fish==OK) show_object(player.x+3,player.y+2,player.current_fish+20);
 			} 		 			
 		}
 		
 		if (player.x==18) {player.sens = SENS2;player.x=15;player.col=5;}
 		if (player.x==0) {player.sens = SENS1;player.x=3;player.col=0;}
 		
 		if ( (player.x<16) && (player.x>2) ) xwarn = player.x;
 		if (player.x<3) xwarn=3;
 		if (player.x>15) xwarn=15;
 		
 		   if (timer2==2) {for(i=0;i<4;i++) put_char(xwarn+i+1,player.y+4,200);}
 		   if (timer2==3) {for(i=0;i<4;i++) put_char(xwarn+i+1,player.y+4,201);}
 		   if (timer2==4) {for(i=0;i<4;i++) put_char(xwarn+i+1,player.y+4,202);}
        
 		
}


void move_player_right(void)
{
	if (player.col<5) {
		player.oldx = player.x;
		player.oldcol = player.col;
		player.col++;
		
		player.x++;
		render_player(OK);
		delay(4);
		show_buffer();
		player.x++;
		render_player(OK);
		delay(4);
		show_buffer();
		player.x++;
		//render_player(OK);		
	} else renderPlayer = NOK;
}

void move_player_left(void)
{
	if (player.col>0) {
		player.oldx = player.x;
		player.oldcol = player.col;
		player.col--;
		
		player.x--;
		render_player(OK);
		delay(4);
		show_buffer();
		player.x--;
		render_player(OK);
		delay(4);
		show_buffer();
		player.x--;
		//render_player(OK);

	} else renderPlayer = NOK;
	
}

void render_vague(char move)
{
	char x;
	
	if (vague==0)
	{
		for (x=3;x<21;x+=2)
		{
    	     		put_char(x,player.y+5,207);
    	     		put_char(x+1,player.y+5,215);
    		}
    	}
    	else
	for (x=3;x<21;x+=2)
	{
     		put_char(x,player.y+5,215);
     		put_char(x+1,player.y+5,207);
	}
	
	if (move==OK) vague++;
	if (vague==2) vague = 0;
	    	
}
char render_laMer(char move)
{
    char x,y,offsetx,offsety;    
    
  render_vague(move);

    offsetx = 3;
    for (x=0;x<6;x++)
    {
        offsety = 6;
        for (y=0;y<9;y++)
        {
                if (y>=player.flotaison) {show_object(offsetx,offsety,laMer_poisson[x][y]);}
                offsety+=2;
       	}
       	offsetx+=3;
    }
    
    /*
    for (x=0;x<18;x+=2)
    {
    	     put_char(3+x,player.y+4,207);
    	     put_char(3+x+1,player.y+4,215);
    }*/
    
    show_buffer();
    return OK;
}

char render_laMerWork()
{
    char x,y,offsetx,offsety;
    
    offsetx = 3;
    for (x=0;x<6;x++)
    {
    	offsety = 6;
        for (y=0;y<9;y++)
        {
            if (y>=player.flotaison)
             if (laMer_work[x][y]!=0)
             	show_object(offsetx,offsety,ZAP);
             else
             	show_object(offsetx,offsety,laMer_poisson[x][y]);
             
             offsety+=2;
        }
        offsetx+=3;
    }
    
    show_buffer();
    return OK;
}	

void erase_player(char x,char y)
{
    show_object(x,y-2,ERASE_3x2);
    show_object(x,y,ERASE_3x1);    
}


void init_laMer(byte level)
{
     char x,y;
        player.tombe_auto=120;
        for (x=0;x<6;x++)
            for (y=0;y<9;y++)
            {
                 if (level==1) {laMer_poisson[x][y] = level1_map[x][y];}
                 if (level==2) {laMer_poisson[x][y] = level2_map[x][y];}
                 if (level==3) {laMer_poisson[x][y] = level3_map[x][y];}
                 if (level==4) {laMer_poisson[x][y] = level4_map[x][y];}
                 if (level==5) {laMer_poisson[x][y] = level5_map[x][y];}
                 if (level==6) {laMer_poisson[x][y] = level6_map[x][y];}
                 if (level==7) {laMer_poisson[x][y] = level7_map[x][y];}
                 if (level==8) {laMer_poisson[x][y] = level8_map[x][y];}
                 if (level==9) {laMer_poisson[x][y] = level8_map[x][y];}
                 if (level==10) {laMer_poisson[x][y] = level10_map[x][y];}
                 if (level==11) {laMer_poisson[x][y] = level11_map[x][y];}
                 if (level==12) {laMer_poisson[x][y] = level12_map[x][y];}
                 if (level==13) {laMer_poisson[x][y] = level13_map[x][y];}
                 if (level==14) {laMer_poisson[x][y] = level14_map[x][y];}
                 if (level==15) {laMer_poisson[x][y] = level15_map[x][y];}
                 if (level==16) {laMer_poisson[x][y] = level16_map[x][y];}
                 if (level==17) {laMer_poisson[x][y] = level17_map[x][y];}
                 if (level==18) {laMer_poisson[x][y] = level18_map[x][y];}
                                                   
                 if (level==30) {laMer_poisson[x][y] = normal01_map[x][y];}
                 if (level==31) {laMer_poisson[x][y] = normal001_map[x][y];}
                 if (level==32) {laMer_poisson[x][y] = normal07_map[x][y];}
                 if (level==33) {laMer_poisson[x][y] = normal04_map[x][y];}
                 if (level==34) {laMer_poisson[x][y] = normal11_map[x][y];}
                 if (level==35) {laMer_poisson[x][y] = normal16_map[x][y];}                 
                 if (level==36) {laMer_poisson[x][y] = normal02_map[x][y];}
                 if (level==37) {laMer_poisson[x][y] = normal08_map[x][y];}
                 if (level==38) {laMer_poisson[x][y] = normal03_map[x][y];}
                 if (level==39) {laMer_poisson[x][y] = normal12_map[x][y];}
                 if (level==40) {laMer_poisson[x][y] = normal15_map[x][y];}                 
                 if (level==41) {laMer_poisson[x][y] = normal17_map[x][y];}                 
                 if (level==42) {laMer_poisson[x][y] = normal20_map[x][y];}                 
                 if (level==43) {laMer_poisson[x][y] = normal29_map[x][y];}                 
                 if (level==44) {laMer_poisson[x][y] = normal003_map[x][y];}
                 if (level==45) {laMer_poisson[x][y] = normal09_map[x][y];}
                 if (level==46) {laMer_poisson[x][y] = normal002_map[x][y];}
                 if (level==47) {laMer_poisson[x][y] = normal004_map[x][y];}
                 if (level==48) {laMer_poisson[x][y] = normal05_map[x][y];}
                 if (level==49) {laMer_poisson[x][y] = normal06_map[x][y];}
                 if (level==50) {laMer_poisson[x][y] = normal18_map[x][y];}                 
                 if (level==51) {laMer_poisson[x][y] = normal005_map[x][y];}
                 if (level==52) {laMer_poisson[x][y] = normal007_map[x][y];}
                 if (level==53) {laMer_poisson[x][y] = normal10_map[x][y];}
                 if (level==54) {laMer_poisson[x][y] = normal13_map[x][y];}
                 if (level==55) {laMer_poisson[x][y] = normal14_map[x][y];}
		 if (level==56) {laMer_poisson[x][y] = normal27_map[x][y];}                 
                 if (level==57) {laMer_poisson[x][y] = normal008_map[x][y];}                 
                 if (level==58) {laMer_poisson[x][y] = normal19_map[x][y];}                 
                 if (level==59) {laMer_poisson[x][y] = normal21_map[x][y];}                 
                 if (level==60) {laMer_poisson[x][y] = normal28_map[x][y];}                 
                 if (level==61) {laMer_poisson[x][y] = normal30_map[x][y];}                 
                 if (level==62) {laMer_poisson[x][y] = normal006_map[x][y];}
                 if (level==63) {laMer_poisson[x][y] = normal22_map[x][y];}                                                   
                 if (level==64) {laMer_poisson[x][y] = normal24_map[x][y];}                 
                 if (level==65) {laMer_poisson[x][y] = normal26_map[x][y];}                 
                 if (level==66) {laMer_poisson[x][y] = normal23_map[x][y];}                 
                 if (level==67) {laMer_poisson[x][y] = normal25_map[x][y];}                 
            }
                
        for (x=0;x<6;x++)
            for (y=0;y<9;y++)
                laMer_work[x][y] = 0;
}

char retourne_laMer_work(char px,char py)
{
    if (px<0) return 127;
    if (px>5) return 127;
    if (py<0) return 127;
    if (py>8) return 127;
    
    if (laMer_work[px][py]==0) return 127;
    
    return laMer_work[px][py];
}

char retourne_laMer(char px,char py)
{
    if (px<0) return 127;
    if (px>5) return 127;
    if (py<0) return 127;
    if (py>8) return 127;
    
    return laMer_poisson[px][py];
}


char check_laMer()
{
    char x,y,sortie,cont;

    cont = 0;
    
    /* On initialise le tableau de travail */
    for (x=0;x<6;x++)
        for (y=0;y<9;y++)
            laMer_work[x][y] = 0;
            
    /* On scanne la première ligne pour voir ce qui potentiellement pourrait sortir de l'eau */
    /* Ce qui pourrait sortir de l'eau est un poisson en entouré de 2 autres ou des bulles*/            
    for (x=0;x<6;x++)
    {
        if (retourne_laMer(x,player.flotaison)!=0)
        {
            /* Y a t'il un bloc à droite et à gauche du courant ? */
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x+1,player.flotaison) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x-1,player.flotaison) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2; cont = 1;}
            /* Y a t'il un 3 bloc en vertical ? */     
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+1) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+2) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2; cont = 1;}
            /* A t'on un L ?  O   */ 
            /*                oo  */    
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+1) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x+1,player.flotaison+1) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2;}
            /* A t'on un L inversé ?     O   */
            /*                          oo   */     
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+1) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x-1,player.flotaison+1) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2;}
            /* oO */
            /* o  */ 
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x+1,player.flotaison) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+1) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2;}
            /* oO */
            /*  o */     
            if (
                 ( retourne_laMer(x,player.flotaison)==retourne_laMer(x,player.flotaison+1) )
                 && ( retourne_laMer(x,player.flotaison)==retourne_laMer(x-1,player.flotaison) )
               ) /* On met un poids pour dire qu'il est suceptible de sortir */
                 {laMer_work[x][player.flotaison] = 2;}
                 
            if (retourne_laMer(x,player.flotaison)==FB) /* Bulle */
                   {laMer_work[x][player.flotaison]=5; }          
        }
    } 
        
    for (x=0;x<6;x++)
    {
        if (laMer_work[x][player.flotaison] > 1)
           {laMer_work[x][player.flotaison] = laMer_poisson[x][player.flotaison];cont=1;}
        else
            laMer_work[x][player.flotaison] = 0; /* Ca sortira pas */
    }  

    if (cont==0) 
    {
    	for (x=0;x<6;x++)
    	 for (y=0;y<9;y++) laMer_work[x][y] = 0;
    	 
    	 return NOK;
    }
    


    /* On regarde tout ce qui est attaché à la sortie de l'eau */
    sortie = 0;
    while (sortie==0)
    {
       sortie = 1;
       for (x=0;x<6;x++)
       {
           for (y=player.flotaison;y<9;y++)
           {
               if (laMer_work[x][y]==0) /* si on à pas encore traité la case */
               if (  /* si sur une case adjacente on à la mème donnée on la marque */
                       (retourne_laMer(x,y)==retourne_laMer_work(x+1,y)) 
                    || (retourne_laMer(x,y)==retourne_laMer_work(x-1,y)) 
                    || (retourne_laMer(x,y)==retourne_laMer_work(x,y+1)) 
                    || (retourne_laMer(x,y)==retourne_laMer_work(x,y-1)) 
                    ) 
                    {
                        laMer_work[x][y] = laMer_poisson[x][y];
                        sortie=0; /* et on refait une passe */
                    }
           }
       }
    }   
    
        	/* Affichage du combo */
        	if (player.plyscore_combo>1)
        	{
        		if (player.sens==SENS1)
        		{
        	       put_char(player.x,player.y+3,231);        		        		
                   put_char(player.x+1,player.y+3,48+player.plyscore_combo);  
                }
                else
                {
        	       put_char(player.x+4,player.y+3,231);        		        		
                   put_char(player.x+5,player.y+3,48+player.plyscore_combo);                      
                }
    		}
         
             show_buffer();
        	if (player.plyscore_combo>0)
        	{
    		
               enable_nmi();
               play_sound(3);
               delay(6);
               disable_nmi(); 
}

/*
    		enable_nmi();
    		play_sound(1);
    		delay(5);
    		disable_nmi();
*/
    	for (x=0;x<2;x++) /* On fait clignoter ce qu'il y a à dégager ! */
    	{
    		render_laMerWork();
    		render_laMer(OK);    		 
               	    		
    	}
        return OK;
      
}


char reduce_laMer()
{
    char a,x,y;
    char a_degager[10];
    char sortie;
    char reduit;
    char i;
    
    unsigned plyscore_pass;

    plyscore_pass = 0;
    
    reduit = NOK;
    
    for (a=0;a<10;a++) a_degager[a] = 0;
    
        /* On va dégager ce qu'il y à a dégager */
        for (x=0;x<6;x++)
        for (y=0;y<9;y++)
            if (retourne_laMer_work(x,y)<10) /* Evite le bug du 127 */
            	a_degager[retourne_laMer_work(x,y)]++;
            
        for (a=1;a<10;a++) /* on va traite les poissons et les bulles pas le 0 = vide*/
            if ((a_degager[a]>=3) || ((a==9) && (a_degager[9]>0)))
            {  reduit = OK;
               for (x=0;x<6;x++)
                   for (y=0;y<9;y++)
                      if (retourne_laMer_work(x,y)==a) 
                      {
                      	laMer_poisson[x][y]=0;
                      	plyscore_pass++;
                      }
            }
                                            
        /*cas particulier des bulles*/
        for (x=0;x<6;x++)
             for (y=0;y<9;y++)
                if (retourne_laMer_work(x,y)==FB) 
                	{
                		laMer_poisson[x][y]=0; 
                		plyscore_pass++;
                	}
                  
        
        for (i=0;i<player.plyscore_combo;i++)
            if (plyscore<32000) plyscore += plyscore_pass;
        
        show_plyscore();    		
        
        
        /* On va faire remonter les poissons*/
        sortie = 0;
        while (sortie==0)
        {
        	sortie = 1;
        	for (x=0;x<6;x++)
         		for (y=player.flotaison;y<8;y++)
             		if ((laMer_poisson[x][y]==0) && (laMer_poisson[x][y+1]!=0))
             		{
                	 laMer_poisson[x][y] = laMer_poisson[x][y+1];
                	 laMer_poisson[x][y+1]=0;                
                	 sortie = 0;
             		}
         }
         
        for (x=0;x<6;x++)
            for (y=0;y<9;y++)
                laMer_work[x][y] = 0;           	
		
         return reduit;
}

char can_i_put_fish()
{
     if (laMer_poisson[player.col][8]!=0)
     {      		
     		return NOK;
     }
     
     return OK;
 }


/* Met un poisson à l'eau par rapport à la position du joueur */
/* Retourne 0 sur impossible, 1 si possible */
char put_fish()
{
     char x,y,i;
     
     if (laMer_poisson[player.col][8]!=0)
     { 
     		if (is_last_line_full()==OK) gameOver = 1;
     		return NOK;
     }
     else
     {
           /* On décale les poissons de la ligne d'un vers le bas, par rapport à la flotaison */
           x = player.col;
           for (y=8;y>player.flotaison;y--)
           {
               laMer_poisson[x][y] = laMer_poisson[x][y-1];
           }
           /* Et on insère le nouveau poisson */
           laMer_poisson[x][player.flotaison] = player.current_fish;
           
           /* On va effectuer du rendering */
	   
	   for (i=1;i<4;i++)
	   {
           	render_player(NOK);
           	if (player.sens==SENS1)
           	   show_object(player.x,player.y+2+i,player.current_fish+20); /* décale d'1 vers le bas */
             else
              	show_object(player.x+3,player.y+2+i,player.current_fish+20);   	
           	if (i<3) delay(3);
           	//disable_nmi();
           	show_buffer();
	   }	   	   
	   	              
        render_laMer(NOK);
        show_buffer();
     }
     
     
     player.compteurlance++;
     return OK;
}

void show_fond(byte level)
{
     char x,y;
     paint_number_bleu_clair_inverse();
     if (level==1) {};



     for (x=0;x<MAXX;x++) for (y=0;y<MAXY;y++) put_char(x,y,204);
     
          for (x=0;x<MAXX;x++)
     {
         put_char(x,7,209);put_char(x,8,209);
         put_char(x,9,237);put_char(x,10,237);
         put_char(x,11,206);put_char(x,12,206);put_char(x,13,206);
         put_char(x,14,206);put_char(x,15,206);put_char(x,16,206);
         put_char(x,17,204);put_char(x,18,204);put_char(x,19,204);
         put_char(x,20,238);put_char(x,21,238);
         put_char(x,22,246);put_char(x,23,246);
         
     }
     for (y=0;y<23+1;y++) {put_char(2,y,29);put_char(21,y,29);}
     for (x=3;x<20+1;x++) {put_char(x,23,121);/*put_char(x,4,94);*/}
     for (x=24;x<28+1;x++) {put_char(x,3,29);put_char(x,6,29);}
     for (y=3;y<6+1;y++) {put_char(24,y,29);put_char(28,y,29);}
     
     for (x=3;x<21;x++)
     	for (y=0;y<4;y++)
     		put_char(x,y,204);
     
     for (x=0;x<2;x++)
     	for (y=0;y<4;y++)
     		put_char(x,y,206);

     for (x=22;x<32;x++)
     	for (y=0;y<4;y++)
     		put_char(x,y,206);
     		
     put_char(0,4,205);put_char(1,4,205);
     put_char(22,4,205);put_char(23,4,205);
     put_char(29,4,205);put_char(30,4,205);put_char(31,4,205);
     
     put_char(0,5,204);put_char(1,5,204);
     put_char(22,5,204);put_char(23,5,204);
     put_char(29,5,204);put_char(30,5,204);put_char(31,5,204);
     
     put_char(0,6,208);put_char(1,6,216);
     put_char(22,6,208);put_char(23,6,216);
     put_char(29,6,208);put_char(30,6,216);put_char(31,6,208);

/*
     for (x=0;x<2;x++)
     	for (y=7;y<24;y++)
     		put_char(x,y,209);

     for (x=22;x<32;x++)
     	for (y=7;y<24;y++)
     		put_char(x,y,209);*/
     		
     put_char(24,3,212);put_char(28,3,213);put_char(24,6,211);put_char(28,6,210);
     put_char(2,23,211);put_char(21,23,210);
     
     //SWITCH
     for (x=0;x<7;x++)
      put_char(23+x,2,217+x);     
     //print_at(23,2,"SWITCH.");
     put_char(23,11,224);put_char(24,11,225);put_char(25,11,226);put_char(26,11,227);put_char(27,11,228);put_char(28,11,229);put_char(29,11,230);
     //print_at(23,11,"SCORE :");
     //print_at(24,13,"00000");
     
          
}


char go_nextLevel()
{	
    //byte hasard;
    int x;
    char plyscore_to_add,parcours;

     char zapx,zapy;     
     
     player.level++;
     if (player.level==endLevel) return 0;
     
    /* Anim et le calcul du plyscore supplémentaire pour la flotaison !! */
    plyscore_to_add = 8 - player.flotaison;
    zapy = 21;
    for (parcours = plyscore_to_add;parcours>=0;parcours--)
    {
    	zapx = 3;
    	for (x=0;x<6;x++)
    	{
    		show_object(zapx,zapy,ZAP);
    		zapx+=3;    		
    	}
    	zapy-=2;
    	
    	if (plyscore<32000) 	plyscore = plyscore + plyscore_to_add   	;
    	show_plyscore(); 
    	//delay(5);   		    	
    	show_buffer();
    }
    
    //rec(0,8,4,31,29,28);    
    rec(2,8,4,19,29,28);    
		
	print_at(5,9, "CONGRATULATION");
	print_at(5,10,"    NOW GO    ");
	print_at(5,11,"TO NEXT LEVEL ");
	//center_string(10,"NOW GO TO NEXT LEVEL");   	
	show_buffer();
    enable_nmi();
    play_sound(4);	
	delay(100);
    disable_nmi();

	//player.level++;
	if (player.level != endLevel)
	{
		init_laMer(player.level);
		reinit_player(); 
		renderLaMer = OK;
		renderPlayer = OK;
		renderSwitch = OK;
		renderFond = OK;
		
	}

 return 0;
	
}

char action_put_fish()
{
			char i,result;
			
    			toucheRelachee=NOK;   
	                result = put_fish();		
    			if (check_laMer()==OK) /* Si il y à quelquechose à sortir */    			
    			while (reduce_laMer()==OK)
    			{
    				player.plyscore_combo++;
    				if (check_laMer()==NOK) break;
    			}
    			player.plyscore_combo = 1;
    			
                  
                  	// On efface le combo
                  	//for (i=3;i<20+1;i++) put_char(i,23,121);
         
    			render_laMer(NOK);
    			
    			if (check_next_level()==OK) {go_nextLevel();}
    			else 
    			{
    				if (result==OK) 
                       		{
                                    player.current_fish = player.stock_fish;
                                    for (i=0;i<2;i++)
                                    {
                                    	player.stock_fish = next_fish_random();
                                    	// On cheat un peut le hasard pour éviter d'avoir toujours le mème poisson
                                    	if (player.stock_fish!=player.current_fish) break;
                                    }
                       		}
    			}
    			render_player(OK);
    			
    			/* Si la dernière ligne est pleine on ne peut plus rien faire */
    			if (is_last_line_full()==OK) gameOver = 1;   
    			
    			return result; 			    			

}

void pause_game()
{
     char sortie = 0;
        
            renderLaMer = OK;
    renderPlayer = OK;
    renderplyscore = OK;
    renderSwitch = OK;
    renderFond = OK;
        
		disable_nmi();
		paint_number_bleu_fonce();
		rec(0,3,15,31,29,28);
		center_string(10,"PAUSE");
		show_buffer();
		enable_nmi();
		 while(keypad_1==3){};
		sortie = 0;
		
		while (sortie == 0)
		{
		 if ( keypad_1==3 ) {sortie = CONTINUE;}
        }     
         while(keypad_1==3){};
}
char render_gameover_menu()
{
     char sortie,x,y,m,tr;
     
     m=0;
     tr=OK;
     play_sound(6);
		disable_nmi();
		paint_number_bleu_fonce();
		//for (x=3;x<21;x++)
		 //for (y=5;y<23;y++)
	
		 for (x=3;x<21;x++)
		 {
		 for (y=23;y>4;y--)
		 {
		     put_char(x,y,203);
         }
         show_buffer();
         }    
		rec(0,9,8,31,29,28);
		center_string(10,txt_gameover);
		center_string(11,txt_finalscore);
		print_at(12,13,str(plyscore));
		center_string(15,txt_continue);
		show_buffer();
		enable_nmi();
		sortie = 0;
		
		while (sortie == 0)
		{
 
              if (joypad_1 & LEFT) m--;
              if (joypad_1 & RIGHT) m++;
              if (m<0) m=0;
              if (m>1) m=1;
              disable_nmi();
              if ((m==0) && (tr==OK)) {put_char(16,15,235);put_char(24,15,32);tr=NOK;}
              if ((m==1) && (tr==OK)) {put_char(16,15,32);put_char(24,15,235);tr=NOK;} 
              if (!(joypad_1 & LEFT)   && !(joypad_1 & RIGHT) ) tr=OK;
              show_buffer();
              enable_nmi();
              delay(1);             
              if (joypad_1 & FIRE1) 
              {
                           if (m==0) sortie = CONTINUE;
                           else sortie = 99;
              }
        }
        
        for (x=0;x<MAXX;x++)
	    for (y=0;y<MAXY;y++)
		put_char(x,y,SPACE); 
	show_buffer();	
	
        return sortie;
	
}

void endGame()
{
     char x,y;
   		disable_nmi();
   		paint_number_bleu_fonce();
   		for (x=0;x<16;x++)
   		    for (y=0;y<14;y++)
   		        show_object((x*2),(y*2),ETOILE);
   		        
		rec(0,9,8,31,29,28);
		center_string(10,txt_congrat);
		center_string(11,txt_finalscore);
		print_at(12,13,str(plyscore));
		center_string(15,txt_tryscore);	
        show_buffer();	
		enable_nmi();
		pause();
}

void main(void)
{
    
	vague = 0;
     	flag1 = 0;
     	toucheRelachee = OK;
	config = TYPE1;
	difficulte = DNORMAL;
	startLevel = DIFF_NORMAL;
	endLevel = DIFF_END_NORMAL;
	
	set_snd_table(snd_table);
		
	//while ((!(joypad_1 & FIRE1)) &&  (!(joypad_1 & FIRE2))) {}	
		
	//disable_nmi();
	screen_off();
	screen_mode_2_text();
	fill_vram(0,0,0x4000);
   	//put_vram (chrgen,charset,2048);
   	load_patternrle(PATTERNRLE);
   	duplicate_pattern();
     	
     	/* Chargement des couleurs */
     	rle2vram(COLORRLE,coltab);
     	rle2vram(COLORRLE,coltab+2048);
     	rle2vram(COLORRLE,coltab+4096);
     	
     	rle2vram(NAMERLE,chrtab);
     	
/*
     	put_vram (coltab,charset_color,2048); 	
     	put_vram (coltab+2048,charset_color,2048); 
     	put_vram (coltab+2048+2048,charset_color,2048); 
  */   	
      	screen_on();
     	
     	pause();

	disable_nmi();     	
	screen_mode_2_bitmap();
	show_picture(intro);	
	enable_nmi();

  pause();
       	
	
	screen_mode_2_text();

    
       screen(name_table1,name_table2);
     
loop1:     	
     	     	
    /* nmi à l'intérieur !! */
	render_menu(); 		        
    
    gameOver = 0;
    
    
    init_laMer(startLevel);
    init_player(); 
      
 
 loop2:
       
    renderLaMer = OK;
    renderPlayer = OK;
    renderplyscore = OK;
    renderMovePlayerLeft = NOK;
    renderMovePlayerRight = NOK;
    renderBaisseFlotaison = NOK;
    renderSwitch = OK;
    renderFond = OK;
    renderPutFish = NOK;
    
    timer1 = 0;
    timer2 = 0;
    
    while (1)
    {
          /* RENDERING GLOBAL */
          if ( (renderPlayer == OK) || (renderLaMer == OK) || (renderplyscore == OK) || (renderMovePlayerLeft == OK) || (renderMovePlayerRight == OK) )
          {
                             disable_nmi();                      
                             if (renderPutFish == OK) {action_put_fish();renderPutFish=NOK;}
                             if (renderFond == OK) {show_fond(player.level);renderFond=NOK;}
                             if (renderSwitch == OK) {render_switch();renderSwitch=OK;}
                             if (renderBaisseFlotaison == OK) {baisse_flotaison();renderBaisseFlotaison=NOK;}
                             if (renderMovePlayerLeft == OK) {move_player_left();renderMovePlayerLeft = NOK;}
                             if (renderMovePlayerRight == OK) {move_player_right();renderMovePlayerRight = NOK;}
                             if (renderLaMer == OK)  {render_laMer(NOK);renderLaMer=NOK;}
                             if (renderPlayer == OK) {render_player(OK);renderPlayer=NOK;}
                             if (renderplyscore == OK )  {show_plyscore();renderplyscore=NOK;}                                     
                             show_buffer();                     
                             enable_nmi();
                             
                             
          }
          delay(1); // Wait_VBL après le NMI mème si il n'est pas executé d'ailleurs !!
                             
    	timer1 ++;
    	
    	/* Gestion du rendu graphique */    	
    	/* On à afficher le joueur, si celui ci ne bouge pas, on ne le réaffiche pas */    	
    	
/*
    	if (( joypad_1 & LEFT ) && (toucheRelachee==OK) ) {renderMovePlayerLeft=OK;renderPlayer=OK;toucheRelachee=NOK;}
    	if (( joypad_1 & RIGHT ) &&(toucheRelachee==OK) ) {renderMovePlayerRight=OK;renderPlayer=OK;toucheRelachee=NOK;}	
  */  	
    	if (( joypad_1 & LEFT ) ) {renderMovePlayerLeft=OK;renderPlayer=OK;}
    	if (( joypad_1 & RIGHT )) {renderMovePlayerRight=OK;renderPlayer=OK;}	


    	if (config==TYPE1)
    	{
           if (( joypad_1 & FIRE1 ) &&(toucheRelachee==OK) ) 
    	   {    		
                  if (can_i_put_fish()==OK) {play_sound(1);delay(5);renderPutFish = OK;renderPlayer=OK;renderLaMer=OK;renderplyscore=OK;timer2=0;timer1=0;}
           }
    	   if (( joypad_1 & FIRE2 ) &&(toucheRelachee==OK) ) {switch_fish();play_sound(5);delay(2);renderSwitch=OK;renderPlayer=OK;toucheRelachee=NOK;}
        } else
    	if (config==TYPE2)
    	{
           if (( joypad_1 & FIRE2 ) &&(toucheRelachee==OK) ) 
    	   {    		
                  if (can_i_put_fish()==OK) {play_sound(1);delay(5);renderPutFish = OK;renderPlayer=OK;renderLaMer=OK;renderplyscore=OK;timer2=0;timer1=0;}
           }
    	   if (( joypad_1 & FIRE1 ) &&(toucheRelachee==OK) ) {switch_fish();play_sound(5);delay(2);renderSwitch=OK;renderPlayer=OK;toucheRelachee=NOK;}
        } else
        {
           if (( joypad_1 & DOWN ) &&(toucheRelachee==OK) ) 
    	   {    		
                  if (can_i_put_fish()==OK) {play_sound(1);delay(5);renderPutFish = OK;renderPlayer=OK;renderLaMer=OK;renderplyscore=OK;timer2=0;timer1=0;}
           }
    	   if (( joypad_1 & FIRE1 ) &&(toucheRelachee==OK) ) {switch_fish();play_sound(5);delay(2);renderSwitch=OK;renderPlayer=OK;toucheRelachee=NOK;}
        }
    		    
        if (keypad_1==3) {pause_game();}	
    		    	
    	if (timer1==player.tombe_auto) {timer2++;timer1=0;}
    	if (timer2>=5) timer2=4;
    	
    	    	
	    /* Une fois affiché, ne pas l'afficher à chaque tour !!! */            
            
            
	    if (timer2>1)
	    {		            

            	if ( (timer2==2)  && (flag1!=2) )
            		{
                        renderPlayer = OK;
            			flag1 = 2;
            		}
            	else
            	if ( (timer2==3)  && (flag1!=3) )
            		{
            			renderPlayer = OK;
            			flag1 = 3;
            		}    
            	else
            	if ( (timer2==4)  && (flag1!=4) )
            		{
            			renderPlayer = OK;
            			flag1 = 4;
            		}    
            }
            
            
            /* TODO : Faire pareil pour un warning de baisse de flotaison !! */
        
        
            
    	if (timer2>=4)    	
    		if (can_i_put_fish()==OK) {renderPutFish = OK;renderPlayer=OK;renderLaMer=OK;renderplyscore=OK;timer2=0;}
    		
	
    	
    	
    	if (player.compteurlance>=player.vitflot) {renderBaisseFlotaison=OK;renderLaMer=OK;renderPlayer=OK;toucheRelachee=NOK;play_sound(2);delay(20);stop_sound(2);}
    		

// Cheats
    	
    //	if (( joypad_1 & DOWN ) &&(toucheRelachee==OK) ) {renderBaisseFlotaison=OK;renderLaMer=OK;renderPlayer=OK;toucheRelachee=NOK;}	
    //	if (( keypad_1==8 ) &&(toucheRelachee==OK) ) go_nextLevel();

    	
    	if (!(joypad_1 & DOWN) && !(joypad_1 & LEFT) && !(joypad_1 & RIGHT) && !(joypad_1 & FIRE1) && !(joypad_1 & UP) && !(joypad_1 & FIRE2)) toucheRelachee=OK;
    	
    	if (gameOver==1) break;
    	if (player.level == endLevel) break;   
    	
    }

	/* Félicitations */
	/* Faire jolie anim avec poissons */
	if (player.level == endLevel)
	{
        endGame();
	}
	/* Game Over */
		if (gameOver==1) 
           if (render_gameover_menu()==CONTINUE)   {gameOver=0;init_laMer(player.level);plyscore=0;reinit_player();goto loop2;};
	

    
    goto loop1;	
           
           
}
