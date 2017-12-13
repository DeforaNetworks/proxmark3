//-----------------------------------------------------------------------------
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// Low frequency viking tag commands
//-----------------------------------------------------------------------------
#ifndef CMDLFVIKING_H__
#define CMDLFVIKING_H__
int CmdLFViking(const char *Cmd);
int CmdVikingDemod(const char *Cmd);
int CmdVikingRead(const char *Cmd);
int CmdVikingClone(const char *Cmd);
int CmdVikingSim(const char *Cmd);
#endif
