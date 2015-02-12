/************************************************************************************
*                                                                                   *
*   Copyright (c) 2014 Axel Menzel <info@axelmenzel.de>                             *
*                                                                                   *
*   This file is part of RTTR (Run Time Type Reflection)                            *
*   License: MIT License                                                            *
*                                                                                   *
*   Permission is hereby granted, free of charge, to any person obtaining           *
*   a copy of this software and associated documentation files (the "Software"),    *
*   to deal in the Software without restriction, including without limitation       *
*   the rights to use, copy, modify, merge, publish, distribute, sublicense,        *
*   and/or sell copies of the Software, and to permit persons to whom the           *
*   Software is furnished to do so, subject to the following conditions:            *
*                                                                                   *
*   The above copyright notice and this permission notice shall be included in      *
*   all copies or substantial portions of the Software.                             *
*                                                                                   *
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
*   SOFTWARE.                                                                       *
*                                                                                   *
*************************************************************************************/

#ifndef __RTTR_RTTR_ENABLE_H__
#define __RTTR_RTTR_ENABLE_H__

#include <type_traits>

#include "rttr/type.h"

namespace rttr
{

namespace detail
{
   

} // end namespace detail

namespace impl
{
#if 0
/////////////////////////////////////////////////////////////////////////////////////

/*!
 * Returns for a given type T, which is not a pointer, the address to it.
 */
template<typename T>
static void* get_ptr(const T& data, typename std::enable_if<!std::is_pointer<T>::value>::type* = 0)
{
    return const_cast<void*>(reinterpret_cast<const void*>(&data));
}

/*!
 * Returns for a given type T, which is not a pointer, the address to it.
 */
template<typename T>
static void* get_ptr(T& data, typename std::enable_if<!std::is_pointer<T>::value>::type* = 0)
{
    return reinterpret_cast<void*>(&data);
}

/*!
 * Returns for a given type T, which a pointer, the address of the pointed data.
 */
template<typename T>
static void* get_ptr(const T& data, typename std::enable_if<std::is_pointer<T>::value>::type* = 0)
{
    return const_cast<void*>(reinterpret_cast<const void*>(data));
}

/*!
 * Returns for a given type T, which a pointer, the address of the pointed data.
 */
template<typename T>
static void* get_ptr(T& data,  typename std::enable_if<std::is_pointer<T>::value>::type* = 0)
{
    return reinterpret_cast<void*>(data);
}

#endif
/////////////////////////////////////////////////////////////////////////////////////////

//! A simple type_list
template<typename... U> struct type_list {};

} // end namespace impl
} // end namespace rttr

#define TYPE_LIST(...)      rttr::impl::type_list<__VA_ARGS__>

#define RTTR_ENABLE(...) \
public:\
    virtual RTTR_INLINE rttr::type get_type() const { return rttr::impl::get_type_from_instance(this); }  \
    virtual RTTR_INLINE void* get_ptr() { return reinterpret_cast<void*>(this); } \
    virtual RTTR_INLINE rttr::detail::derived_info get_derived_info() { return {reinterpret_cast<void*>(this), rttr::impl::get_type_from_instance(this)}; } \
    typedef TYPE_LIST(__VA_ARGS__) base_class_list; \
private:


#endif // __RTTR_RTTR_ENABLE_H__