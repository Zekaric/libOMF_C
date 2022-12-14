/**************************************************************************************************
file:       OmfElemLineSet
author:     Robbert de Groot
copyright:  2022, Robbert de Groot

description:
Line set element 
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
func: _OmfElemLineSetCreate
**************************************************************************************************/
OmfElemLineSet *_OmfElemLineSetCreate(void)
{
   OmfElemLineSet *elem;

   elem = _OmfMemCreateType(OmfElemLineSet);
   returnNullIf(!elem);

   if (!_OmfElemLineSetCreateContent(elem))
   {
      _OmfMemDestroy(elem);
      return NULL;
   }

   return elem;
}

/**************************************************************************************************
func: _OmfElemLineSetCreateContent
**************************************************************************************************/
OmfBool _OmfElemLineSetCreateContent(OmfElemLineSet * const elem)
{
   _OmfMemClearType(OmfElemLineSet, elem);
   elem->typeElem    = omfElemTypeLINE_SET;
   elem->typeElemSub = omfElemSubTypeLINE_SET_LINE_DEFAULT;

   return omfTRUE;
}

/**************************************************************************************************
func: _OmfElemLineSetDestroyContent
**************************************************************************************************/
void _OmfElemLineSetDestroyContent(OmfElemLineSet * const elem)
{
   returnVoidIf(!elem);

   omfObjDestroyObj(elem->geometry);

   return;
}

/**************************************************************************************************
func: omfElemLineSetGetGeometry
**************************************************************************************************/
OmfGeom *omfElemLineSetGetGeometry(OmfElemLineSet const * const elem)
{
   returnNullIf(
      !omfIsStarted() ||
      !elem);

   return (OmfGeom *) elem->geometry;
}

/**************************************************************************************************
func: omfElemLineSetSetGeometry
**************************************************************************************************/
OmfBool omfElemLineSetSetGeometry(OmfElemLineSet * const elem, 
   OmfGeomLineSet * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !elem);

   elem->geometry = value;

   return omfTRUE;
}
