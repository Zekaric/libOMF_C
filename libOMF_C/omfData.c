/**************************************************************************************************
file:       OmfData
author:     Robbert de Groot
copyright:  2022, Robbert de Groot

description:
Data routines
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
func: _OmfDataCreate
**************************************************************************************************/
OmfData *_OmfDataCreate(OmfDataType const type)
{
   OmfData *data;

   returnNullIf(!omfIsStarted());

   data = _OmfMemCreateType(OmfData);
   returnNullIf(!data);

   if (!_OmfDataCreateContent(data, type))
   {
      _OmfMemDestroy(data);
      return NULL;
   }

   return data;
}

/**************************************************************************************************
func: _OmfDataCreateContent
**************************************************************************************************/
OmfBool _OmfDataCreateContent(OmfData * const data, OmfDataType const type)
{
   returnFalseIf(!omfIsStarted());

   _OmfMemClearType(OmfData, data);

   data->typeData = type;

   return omfTRUE;
}

/**************************************************************************************************
func: _OmfDataDestroyContent
**************************************************************************************************/
void _OmfDataDestroyContent(OmfData * const data)
{
   returnVoidIf(
      !omfIsStarted() ||
      !data);

   omfObjDestroyObj(data->array);
   omfCharDestroy(  data->dateCreated);
   omfCharDestroy(  data->dateModified);
   omfCharDestroy(  data->description);
   omfCharDestroy(  data->name);

   return;
}

/**************************************************************************************************
func: omfDataGetArray
**************************************************************************************************/
OmfArray *omfDataGetArray(OmfData const * const data)
{
   returnNullIf(
      !omfIsStarted() ||
      !data);

   return data->array;
}

/**************************************************************************************************
func: omfDataGetDescription
**************************************************************************************************/
OmfChar *omfDataGetDescription(OmfData const * const data)
{
   returnNullIf(
      !omfIsStarted() ||
      !data);

   return data->description;
}

/**************************************************************************************************
func: omfDataGetLoc
**************************************************************************************************/
OmfDataLoc omfDataGetLoc(OmfData const * const data)
{
   returnIf(
         !omfIsStarted() ||
         !data,
      omfDataLocNONE);

   return data->location;
}

/**************************************************************************************************
func: omfDataGetName
**************************************************************************************************/
OmfChar *omfDataGetName(OmfData const * const data)
{
   returnNullIf(
      !omfIsStarted() ||
      !data);

   return data->name;
}

/**************************************************************************************************
func: omfDataGetType
**************************************************************************************************/
OmfDataType omfDataGetType(OmfData const * const omfData)
{
   returnIf(
         !omfIsStarted() ||
         !omfData,
      omfDataTypeNONE);

   return omfData->typeData;
}

/**************************************************************************************************
func: omfDataSetArray
**************************************************************************************************/
OmfBool omfDataSetArray(OmfData * const data, OmfArray * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !data);

   data->array = value;

   return omfTRUE;
}

/**************************************************************************************************
func: omfDataSetDescription
**************************************************************************************************/
OmfBool omfDataSetDescription(OmfData * const data, OmfChar * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !data);

   omfCharDestroy(data->description);
   data->description = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfDataSetLoc
**************************************************************************************************/
OmfBool omfDataSetLoc(OmfData * const data, OmfDataLoc const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !data);

   data->location = value;

   return omfTRUE;
}

/**************************************************************************************************
func: omfDataSetName
**************************************************************************************************/
OmfBool omfDataSetName(OmfData * const data, OmfChar * const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !data);

   omfCharDestroy(data->name);
   data->name = omfCharClone(value);

   return omfTRUE;
}

/**************************************************************************************************
func: omfDataSetType
**************************************************************************************************/
OmfBool omfDataSetType(OmfData * const omfData, OmfDataType const value)
{
   returnFalseIf(
      !omfIsStarted() ||
      !omfData);

   omfData->typeData = value;

   return omfTRUE;
}
