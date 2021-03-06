/*
 * Copyright (c) 1990, 1991 Stanford University
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Stanford not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  Stanford makes no representations about
 * the suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * STANFORD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL STANFORD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * UList - list object.
 */

#ifndef unidraw_ulist_h
#define unidraw_ulist_h

#include <InterViews/enter-scope.h>
#include <Unidraw/enter-scope.h>

#include <InterViews/_enter.h>

class UList {
public:
    UList(void* = nil);
    virtual ~UList();

    bool IsEmpty();
    void Append(UList*);
    void Prepend(UList*);
    void Remove(UList*);
    void Delete(void*);
    UList* Find(void*);
    UList* First();
    UList* Last();
    UList* End();
    UList* Next();
    UList* Prev();

    void* operator()();
    UList* operator[](int count);
protected:
    void* _object;
    UList* _next;
    UList* _prev;
};

inline bool UList::IsEmpty () { return _next == this; }
inline UList* UList::First () { return _next; }
inline UList* UList::Last () { return _prev; }
inline UList* UList::End () { return this; }
inline UList* UList::Next () { return _next; }
inline UList* UList::Prev () { return _prev; }
inline void* UList::operator() () { return _object; }

#include <InterViews/_leave.h>

#endif
