/*
** LCLint - annotation-assisted static program checker
** Copyright (C) 1994-2001 University of Virginia,
**         Massachusetts Institute of Technology
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 2 of the License, or (at your
** option) any later version.
** 
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** General Public License for more details.
** 
** The GNU General Public License is available from http://www.gnu.org/ or
** the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
** MA 02111-1307, USA.
**
** For information on lclint: lclint-request@cs.virginia.edu
** To report a bug: lclint-bug@cs.virginia.edu
** For more information: http://lclint.cs.virginia.edu
*/
/*
** mtMergeNode.c
*/

# include "lclintMacros.nf"
# include "basic.h"
# include "mtgrammar.h"

extern mtMergeNode mtMergeNode_create (mtMergeClauseList mlist) 
{
  mtMergeNode res = (mtMergeNode) dmalloc (sizeof (*res));
  res->mlist = mlist;
  DPRINTF (("merge node: %s", mtMergeNode_unparse (res)));
  return res;
}

void mtMergeNode_free (/*@only@*/ mtMergeNode node)
{
  mtMergeClauseList_free (node->mlist);
  sfree (node);
}

extern cstring mtMergeNode_unparse (mtMergeNode node)
{
  return message ("merge %q", mtMergeClauseList_unparse (node->mlist));
}
