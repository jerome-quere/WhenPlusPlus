/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Jerome Quere <contact@jeromequere.com>
 *
 * Permission is hereby granted, free  of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction,  including without limitation the rights
 * to use,  copy,  modify,  merge, publish,  distribute, sublicense, and/or sell
 * copies  of  the  Software,  and  to  permit  persons  to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The  above  copyright  notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY  OF ANY KIND, EXPRESS OR
 * IMPLIED,  INCLUDING BUT NOT LIMITED  TO THE  WARRANTIES  OF  MERCHANTABILITY,
 * FITNESS  FOR A  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS  OR  COPYRIGHT  HOLDERS  BE  LIABLE  FOR  ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT  OF  OR  IN  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _WHEN_LAMBDARESOLVER_H_
#define _WHEN_LAMBDARESOLVER_H_

namespace When
{
    template <typename T>
    struct LambdaResolver : public LambdaResolver<decltype(&T::operator())> {};


    template <typename R, typename C, typename ...A>
    struct LambdaResolver<R (C::*)(A...) const> {
	typedef R returnType;
	typedef Promise<R> promiseType;
    };

    template <typename C, typename ...A>
    struct LambdaResolver<void (C::*)(A...) const> {
	typedef void returnType;
	typedef Promise<bool> promiseType;
    };


    template <typename ...P, typename C, typename ...A>
    struct LambdaResolver<Promise<P...> (C::*)(A...) const> {
	typedef Promise<P...> returnType;
	typedef Promise<P...> promiseType;
    };

}


#endif
