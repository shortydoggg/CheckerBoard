typedef struct
	{
	int db_MB;
	int hash_MB;
	int book;
	int allscores;
	char directory[256];
	} ENGINE_OPTIONS;

BOOL CALLBACK AboutDialogFunc(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ThreeMoveDialogFunc(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncOnlineupgrade(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncDownloadprogress(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncSavegame(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncSelectgame(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncAddcomment(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogSearchMask(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogFuncEnginecommand(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DirectoryDialogFunc(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK EngineOptionsFunc(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK EngineDialogFunc(HWND hdwnd, UINT message, WPARAM wParam, LPARAM lParam);
int CenterDialog(HWND hdwnd);
int setengineoptions(HWND hdwnd, int availableMB, ENGINE_OPTIONS *oldoptions, ENGINE_OPTIONS *newoptions);
int getengineoptions(HWND hdwnd, ENGINE_OPTIONS *options);
int getoptionsfromdialog(HWND hdwnd, ENGINE_OPTIONS *options);


//#define MAXGAMES 32000 //maximal number of games per pdn database also defined in PDNfind.h! aargh!


/* engine dialog */
#define IDC_OK 1
#define IDC_CANCEL 2
#define IDC_APPLY 3
#define IDC_SECONDARY 102
#define IDC_PRIMARY 101

/* engine options dialog */
#define IDC_BOOKBEST 1005
#define IDC_BOOKGOOD 1006
#define IDC_BOOKALLKINDS 1007
#define IDC_BOOKOFF 1008
#define IDC_HASHSIZE 1002
#define IDC_EGDBSIZE 1003
#define IDC_STATIC 1004
#define IDC_ALLSCORES 1001
#define IDC_DBDIR 1000
#define IDC_COMBO 1009


/*3-move dialog */
#define IDC_BOARD 1000
#define IDC_MAILPLAY 1001
#define IDC_BARRED 1002

/* directory dialog*/
#define IDC_USER 1001
#define IDC_MATCH 1002
#define IDC_BMP 1003

/* online upgrade dialog */
#define IDC_DOWNLOAD 100
#define IDC_DESCRIPTION 101

/* save game dialog*/
#define IDC_BLACKNAME 1000
#define IDC_WHITENAME 1002
#define IDC_EVENT 1004
#define IDC_DATE 1009
#define IDC_BLACKWINS 1005
#define IDC_WHITEWINS 1006
#define IDC_DRAW 1007
#define IDC_UNKNOWN 1008

/* comment dialog */
#define IDC_COMMENT 1001

// engine command dialog
#define IDC_COMMAND 1001

// search mask dialog
#define IDC_PLAYERNAME 1001
#define IDC_EVENTNAME 1002
#define IDC_DATENAME 1003
#define IDC_COMMENTNAME 1004
#define IDC_SEARCHWITHPOSITION 1005

/* download progress */
#define IDC_DOWNLOADPROGRESSBAR 1012
#define IDC_DOWNLOADTEXT 1010

#define ICON1 11111

/* select game dialog */
/* header control */
#define ID_HEADCONTROL 500
#define PLAYERWIDTH 120
#define RESULTWIDTH 80
#define EVENTWIDTH 440
#define NUMCOLS 4
#define MINWIDTH 10
#define SPACING 8
#define IDC_SELECT 102
#define IDC_DELETE 3
#define IDC_PREVIEW 101


#define MAXUPGRADE 20








