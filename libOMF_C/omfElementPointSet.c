/**************************************************************************************************
file:       OmfElemPntSet
author:     Robbert de Groot
copyright:  2022, Robbert de Groot

description:
Pnt Set routines
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
func: _OmfElemPntSetCreate
**************************************************************************************************/
OmfElemPntSet *_OmfElemPntSetCreate(void)
{
   OmfElemPntSet *elem;

   elem = _OmfMemCreateType(OmfElemPntSet);
   returnNullIf(!elem);

   if (!_OmfElemPntSetCreateContent(elem))
   {
      _OmfMemDestroy(elem);
      return NULL;
   }

   return elem;
}

/**************************************************************************************************
func: _OmfElemPntSetCreateContent
**************************************************************************************************/
OmfBool _OmfElemPntSetCreateContent(OmfElemPntSet * const elem)
{
   _OmfMemClearType(OmfElemPntSet, elem);
   elem->typeElem    = omfElemTypePNT_SET;
   elem->typeElemSub = omfElemSubTypePNT_SET_POINT_DEFAULT;

   return omfTRUE;
}

/**************************************************************************************************
func: _OmfElemPntSetDestroyContent
**************************************************************************************************/
void _OmfElemPntSetDestroyContent(OmfElemPntSet * const elem)
{
   returnVoidIf(!elem);

   omfObjDestroy((OmfObj *) elem->geometry);
   //omfTextureListDestroy(     elem->textureList);
}

/**************************************************************************************************
func: omfElemPntSetGetGeometry
**************************************************************************************************/
OmfGeom *omfElemPntSetGetGeometry(OmfElemPntSet const * const elem)
{
   returnNullIf(
      !omfIsStarted() ||
      !elem);

   return (OmfGeom *) elem->geometry;
}

/**************************************************************************************************
func: omfElemPntSetGetTexture
**************************************************************************************************/
OmfTextureList *omfElemPntSetGetTextureList(OmfElemPntSet const * const elem)
{
   returnNullIf(
      !omfIsStarted() ||
      !elem);

   return elem->textureList;
}

/**************************************************************************************************
func: omfElemPntSetIsTextureListSet
**************************************************************************************************/
OmfBool omfElemPntSetIsTextureListSet(OmfElemPntSet const * const elem)
{
   returnFalseIf(
      !omfIsStarted() ||
      !elem);

   return elem->isTextureListSet;
}

/**************************************************************************************************
func: omfElemPntSetSetGeometry
**************************************************************************************************/
OmfBool omfElemPntSetSetGeometry(OmfElemPntSet * const elem, 
   OmfGeomPntSet * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !elem);

   elem->geometry = value;

   return omfTRUE;
}

/**************************************************************************************************
func: omfElemPntSetSetTexture
**************************************************************************************************/
OmfBool omfElemPntSetSetTextureList(OmfElemPntSet * const elem, 
   OmfTextureList * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !elem);

   elem->textureList      =  value;
   elem->isTextureListSet = (value != NULL);

   return omfTRUE;
}
