//HEADER_GOES_HERE
#ifndef __MSG_H__
#define __MSG_H__

extern int deltaload;
extern BYTE gbBufferMsgs;
extern int pkt_counter;

void __fastcall msg_send_drop_pkt(int pnum, int reason);
void __fastcall msg_send_packet(int pnum, const void *packet, DWORD dwSize);
TMegaPkt *__cdecl msg_get_next_packet();
BOOL __cdecl msg_wait_resync();
void __cdecl msg_free_packets();
int __cdecl msg_wait_for_turns();
void __cdecl msg_process_net_packets();
void __cdecl msg_pre_packet();
void __fastcall DeltaExportData(int pnum);
void *__fastcall DeltaExportItem(void *dst, void *src);
void *__fastcall DeltaExportObject(void *dst, void *src);
void *__fastcall DeltaExportMonster(void *dst, void *src);
void *__fastcall DeltaExportJunk(void *dst);
int __fastcall msg_comp_level(char *begin, void *end);
void __cdecl delta_init();
void __fastcall delta_kill_monster(int mi, BYTE x, BYTE y, BYTE bLevel);
void __fastcall delta_monster_hp(int mi, int hp, BYTE bLevel);
void __fastcall delta_sync_monster(TCmdLocParam1 *packet, BYTE level);
void __fastcall delta_sync_golem(TCmdGolem *pG, int pnum, BYTE bLevel);
void __fastcall delta_leave_sync(BYTE bLevel);
BOOL __fastcall delta_portal_inited(int i);
BOOL __fastcall delta_quest_inited(int i);
void __fastcall DeltaAddItem(int ii);
void __cdecl DeltaSaveLevel();
void __cdecl DeltaLoadLevel();
void __fastcall NetSendCmd(BOOL bHiPri, BYTE bCmd);
void __fastcall NetSendCmdGolem(BYTE mx, BYTE my, BYTE dir, BYTE menemy, int hp, int cl);
void __fastcall NetSendCmdLoc(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void __fastcall NetSendCmdLocParam1(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1);
void __fastcall NetSendCmdLocParam2(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2);
void __fastcall NetSendCmdLocParam3(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2, WORD wParam3);
void __fastcall NetSendCmdParam1(BOOL bHiPri, BYTE bCmd, WORD wParam1);
void __fastcall NetSendCmdParam2(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2);
void __fastcall NetSendCmdParam3(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2, WORD wParam3);
void __fastcall NetSendCmdQuest(BOOL bHiPri, BYTE q);
void __fastcall NetSendCmdGItem(BOOL bHiPri, BYTE bCmd, BYTE mast, BYTE pnum, int ii);
void __fastcall NetSendCmdGItem2(BOOL usonly, BYTE bCmd, BYTE mast, BYTE pnum, struct TCmdGItem *p);
bool __fastcall NetSendCmdReq2(BYTE bCmd, BYTE mast, BYTE pnum, struct TCmdGItem *p);
void __fastcall NetSendCmdExtra(struct TCmdGItem *p);
void __fastcall NetSendCmdPItem(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void __fastcall NetSendCmdChItem(BOOL bHiPri, BYTE bLoc);
void __fastcall NetSendCmdDelItem(BOOL bHiPri, BYTE bLoc);
void __fastcall NetSendCmdDItem(BOOL bHiPri, int ii);
void __fastcall NetSendCmdDamage(BOOL bHiPri, BYTE bPlr, DWORD dwDam);
void __fastcall NetSendCmdString(int pmask, const char *pszStr);
void __fastcall RemovePlrPortal(int pnum);
int __fastcall ParseCmd(int pnum, TCmd *pCmd);
void __fastcall DeltaImportData(BYTE cmd, DWORD recv_offset);
void *__fastcall DeltaImportItem(void *src, void *dst);
void *__fastcall DeltaImportObject(void *src, void *dst);
void *__fastcall DeltaImportMonster(void *src, void *dst);
void __fastcall DeltaImportJunk(void *src);
int __fastcall On_SYNCDATA(void *packet, int pnum);
int __fastcall On_WALKXY(struct TCmdLoc *pCmd, int pnum);
int __fastcall On_ADDSTR(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDMAG(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDDEX(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_ADDVIT(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_SBSPELL(struct TCmdParam1 *pCmd, int pnum);
void msg_errorf(const char *pszFmt, ...);
int __fastcall On_GOTOGETITEM(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_REQUESTGITEM(struct TCmdGItem *pCmd, int pnum);
BOOL __fastcall i_own_level(int nReqLevel);
int __fastcall On_GETITEM(struct TCmdGItem *pCmd, int pnum);
BOOL __fastcall delta_get_item(struct TCmdGItem *pI, BYTE bLevel);
int __fastcall On_GOTOAGETITEM(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_REQUESTAGITEM(struct TCmdGItem *pCmd, int pnum);
int __fastcall On_AGETITEM(struct TCmdGItem *pCmd, int pnum);
int __fastcall On_ITEMEXTRA(struct TCmdGItem *pCmd, int pnum);
int __fastcall On_PUTITEM(struct TCmdPItem *pCmd, int pnum);
void __fastcall delta_put_item(struct TCmdPItem *pI, int x, int y, BYTE bLevel);
void __fastcall check_update_plr(int pnum);
int __fastcall On_SYNCPUTITEM(struct TCmdPItem *pCmd, int pnum);
int __fastcall On_RESPAWNITEM(struct TCmdPItem *pCmd, int pnum);
int __fastcall On_ATTACKXY(struct TCmdLoc *pCmd, int pnum);
int __fastcall On_SATTACKXY(struct TCmdLoc *pCmd, int pnum);
int __fastcall On_RATTACKXY(struct TCmdLoc *pCmd, int pnum);
int __fastcall On_SPELLXYD(struct TCmdLocParam3 *pCmd, int pnum);
int __fastcall On_SPELLXY(struct TCmdLocParam2 *pCmd, int pnum);
int __fastcall On_TSPELLXY(struct TCmdLocParam2 *pCmd, int pnum);
int __fastcall On_OPOBJXY(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_DISARMXY(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_OPOBJT(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_ATTACKID(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_ATTACKPID(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_RATTACKID(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_RATTACKPID(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_SPELLID(struct TCmdParam3 *pCmd, int pnum);
int __fastcall On_SPELLPID(struct TCmdParam3 *pCmd, int pnum);
int __fastcall On_TSPELLID(struct TCmdParam3 *pCmd, int pnum);
int __fastcall On_TSPELLPID(struct TCmdParam3 *pCmd, int pnum);
int __fastcall On_KNOCKBACK(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_RESURRECT(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_HEALOTHER(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_TALKXY(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_NEWLVL(struct TCmdParam2 *pCmd, int pnum);
int __fastcall On_WARP(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_MONSTDEATH(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_KILLGOLEM(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_AWAKEGOLEM(struct TCmdGolem *pCmd, int pnum);
int __fastcall On_MONSTDAMAGE(struct TCmdParam2 *pCmd, int pnum);
int __fastcall On_PLRDEAD(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_PLRDAMAGE(struct TCmdDamage *pCmd, int pnum);
int __fastcall On_OPENDOOR(struct TCmdParam1 *pCmd, int pnum);
void __fastcall delta_sync_object(int oi, BYTE bCmd, BYTE bLevel);
int __fastcall On_CLOSEDOOR(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_OPERATEOBJ(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_PLROPOBJ(struct TCmdParam2 *pCmd, int pnum);
int __fastcall On_BREAKOBJ(struct TCmdParam2 *pCmd, int pnum);
int __fastcall On_CHANGEPLRITEMS(struct TCmdChItem *pCmd, int pnum);
int __fastcall On_DELPLRITEMS(struct TCmdDelItem *pCmd, int pnum);
int __fastcall On_PLRLEVEL(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_DROPITEM(struct TCmdPItem *pCmd, int pnum);
int __fastcall On_SEND_PLRINFO(struct TCmdPlrInfoHdr *pCmd, int pnum);
int __fastcall On_ACK_PLRINFO(struct TCmdPlrInfoHdr *pCmd, int pnum);
int __fastcall On_PLAYER_JOINLEVEL(struct TCmdLocParam1 *pCmd, int pnum);
int __fastcall On_ACTIVATEPORTAL(struct TCmdLocParam3 *pCmd, int pnum);
void __fastcall delta_open_portal(int pnum, BYTE x, BYTE y, BYTE bLevel, BYTE bLType, BYTE bSetLvl);
int __fastcall On_DEACTIVATEPORTAL(struct TCmd *pCmd, int pnum);
int __fastcall On_RETOWN(struct TCmd *pCmd, int pnum);
int __fastcall On_SETSTR(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETDEX(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETMAG(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_SETVIT(struct TCmdParam1 *pCmd, int pnum);
int __fastcall On_STRING(struct TCmdString *pCmd, int pnum);
int __fastcall On_SYNCQUEST(struct TCmdQuest *pCmd, int pnum);
int __fastcall On_ENDSHIELD(struct TCmd *pCmd, int pnum);
#ifdef _DEBUG
int __fastcall On_CHEAT_EXPERIENCE(struct TCmd *pCmd, int pnum);
int __fastcall On_CHEAT_SPELL_LEVEL(struct TCmd *pCmd, int pnum);
#endif
int __cdecl On_DEBUG(struct TCmd *pCmd);
int __fastcall On_NOVA(struct TCmdLoc *pCmd, int pnum);
int __fastcall On_SETSHIELD(struct TCmd *pCmd, int pnum);
int __fastcall On_REMSHIELD(struct TCmd *pCmd, int pnum);

#endif /* __MSG_H__ */
