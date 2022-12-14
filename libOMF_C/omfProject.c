/**************************************************************************************************
file:       OmfProj
author:     Robbert de Groot
copyright:  2022, Robbert de Groot

description:
Project routines
**************************************************************************************************/

/**************************************************************************************************
MIT License

Copyright (c) !!!!YEAR!!!!, Robbert de Groot

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT 
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT 
OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**************************************************************************************************/

/**************************************************************************************************
include:
**************************************************************************************************/
#include "pch.h"

/**************************************************************************************************
local:
constant:
**************************************************************************************************/

/**************************************************************************************************
type:
**************************************************************************************************/

/**************************************************************************************************
variable:
**************************************************************************************************/

/**************************************************************************************************
prototype:
**************************************************************************************************/

/**************************************************************************************************
global:
function:
**************************************************************************************************/
/**************************************************************************************************
func: _OmfProjCreate
**************************************************************************************************/
OmfProj *_OmfProjCreate(void)
{
   OmfProj *proj;

   returnNullIf(!omfIsStarted());

   proj = _OmfMemCreateType(OmfProj);
   returnNullIf(!proj);

   if (!_OmfProjCreateContent(proj))
   {
      _OmfMemDestroy(proj);
      return NULL;
   }

   return proj;
}

/**************************************************************************************************
func: _OmfProjCreateContent
**************************************************************************************************/
OmfBool _OmfProjCreateContent(OmfProj * const proj)
{
   returnFalseIf(!omfIsStarted());

   _OmfMemClearType(OmfProj, proj);

   proj->elemList = omfListCreate();
   returnFalseIf(!proj->elemList);

   return omfTRUE;
}

/**************************************************************************************************
func: _OmfProjDestroyContent
**************************************************************************************************/
void _OmfProjDestroyContent(OmfProj * const proj)
{
   returnVoidIf(!proj);

   omfCharDestroy(proj->author);
   omfCharDestroy(proj->date);
   omfCharDestroy(proj->description);
   omfCharDestroy(proj->name);
   omfCharDestroy(proj->revision);

   return;
}

/**************************************************************************************************
func: omfProjAddElem
**************************************************************************************************/
OmfBool omfProjAddElem(OmfProj *const proj, OmfElem *const elem)
{
   OmfListItem *listItem;

   returnFalseIf(
      !omfIsStarted() ||
      !proj           ||
      (omfObjGetObjType(elem) & omfObjTypeELEM) != omfObjTypeELEM);

   // Create a new list item.
   listItem = omfListItemCreate();
   returnFalseIf(!listItem);

   // Set up the list item.
   omfListItemSetObj(listItem, omfObjFromObj(elem));

   // Add the listItem to the list.
   omfListAppend(proj->elemList, listItem);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjGetAuthor
**************************************************************************************************/
OmfChar *omfProjGetAuthor(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->author;
}

/**************************************************************************************************
func: omfProjGetDate
**************************************************************************************************/
OmfChar *omfProjGetDate(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->date;
}

/**************************************************************************************************
func: omfProjGetDescription
**************************************************************************************************/
OmfChar *omfProjGetDescription(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->description;
}

/**************************************************************************************************
func: omfProjGetName
**************************************************************************************************/
OmfChar *omfProjGetName(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->name;
}

/**************************************************************************************************
func: omfProjGetOrigin
**************************************************************************************************/
OmfCoord omfProjGetOrigin(OmfProj const * const proj)
{
   OmfCoord vec;

   _OmfMemClearType(OmfCoord, &vec);

   returnIf(
         !omfIsStarted() ||
         !proj,
      vec);

   return proj->origin;
}

/**************************************************************************************************
func: omfProjGetRevision
**************************************************************************************************/
OmfChar *omfProjGetRevision(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->revision;
}

/**************************************************************************************************
func: omfProjGetUnits
**************************************************************************************************/
OmfChar *omfProjGetUnits(OmfProj const * const proj)
{
   returnNullIf(
      !omfIsStarted() ||
      !proj);

   return proj->units;
}

/**************************************************************************************************
func: omfProjIsDateSet
**************************************************************************************************/
OmfBool omfProjIsDateSet(OmfProj const * const proj)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   return proj->isDateSet;
}

/**************************************************************************************************
func: omfProjSetAuthor
**************************************************************************************************/
OmfBool omfProjSetAuthor(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->author);
   proj->author = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetDate
**************************************************************************************************/
OmfBool omfProjSetDate(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->date);
   proj->date      = omfCharClone(value);
   proj->isDateSet = (value != NULL);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetDescription
**************************************************************************************************/
OmfBool omfProjSetDescription(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->description);
   proj->description = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetName
**************************************************************************************************/
OmfBool omfProjSetName(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->name);
   proj->name = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetOrigin
**************************************************************************************************/
OmfBool omfProjSetOrigin(OmfProj * const proj, OmfCoord const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   proj->origin = value;

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetRevision
**************************************************************************************************/
OmfBool omfProjSetRevision(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->revision);
   proj->revision = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfProjSetUnits
**************************************************************************************************/
OmfBool omfProjSetUnits(OmfProj * const proj, OmfChar const * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !proj);

   omfCharDestroy(proj->units);
   proj->units = omfCharClone(value);

   return omfTRUE;
}
