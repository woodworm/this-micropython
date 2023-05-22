/**
 * @file   this-micropython/this.c
 * @author woodworm
 * @date   17.5.2023
 * @brief  this C implementation for micropython
 *
 * The MIT License (MIT)
 *
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "py/runtime.h"

#if defined(MODULE_THIS_ENABLED) && MODULE_THIS_ENABLED

#include "py/obj.h"
#include "py/mpprint.h"


STATIC const char the_zen_str[] = "The Zen of µPython\n\n\
Beautiful is better than ugly.\n\
Explicit is better than implicit.\n\
Simple is better than complex.\n\
Complex is better than complicated.\n\
Flat is better than nested.\n\
Sparse is better than dense.\n\
Readability counts.\n\
Special cases aren't special enough to break the rules.\n\
Although practicality beats purity.\n\
Errors should never pass silently.\n\
Unless explicitly silenced.\n\
In the face of ambiguity, refuse the temptation to guess.\n\
There should be one-- and preferably only one --obvious way to do it.\n\
Although that way may not be obvious at first unless you're Dutch.\n\
Now is better than never.\n\
Although never is often better than *right* now.\n\
If the implementation is hard to explain, it's a bad idea.\n\
If the implementation is easy to explain, it may be a good idea.\n\
Namespaces are one honking great idea -- let's do more of those!\n";

STATIC mp_obj_t this_init(void) {
    mp_printf(MP_PYTHON_PRINTER, the_zen_str);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(this_init_fun_obj, this_init);


STATIC const char de_zen_str[] = "De Zen vu µPython\n\n\
Schön isch besser als hässlich.\n\
Usdrücklich isch besser als stillschwigend.\n\
Eifach isch besser als cheibe komplex.\n\
Cheibe komplex isch besser als uuuu kompliziert.\n\
Flach isch besser als mega verschachtlet.\n\
Sparsam isch besser als cheibe dicht.\n\
Leserlich isch uuu wichtig.\n\
Sonderfäll sind nöd speziell gnueg, um gege Regele z'verstosse.\n\
Obwohl praktischi Anwendig Zuberkeit übertrifft.\n\
Fehler dörfet niemals lislig passiere.\n\
Sofern nöd ausdrücklich uf lislig gschalte worde isch.\n\
Widerstoh de Versuechig wenn nöd drus chunsch eifach nume z'rötle.\n\
Es söt nur eine -- und wirklich nur eine -- offesichtliche weg gee, so muesch es mache.\n\
Obwohls am Anfang nöd offensichtlich isch, es sei denn, Du bisch Holländer.\n\
Jetzt isch besser als nie.\n\
Obwohls nie besser isch als *genau* jetzt.\n\
Wenn de Code schwer zum erkläre isch, isches kei guti Idee.\n\
Wenn de Code eifach z'erklären isch, chönds no e gueti Idee sii.\n\
Namespaces isch e mega super Idee -- machemer also me davo!\n";

STATIC mp_obj_t this_ch(void) {
    mp_printf(MP_PYTHON_PRINTER, de_zen_str);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(this_ch_fun_obj, this_ch);


STATIC const mp_rom_map_elem_t this_globals_table[] = {
    {MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_this)},
#if MICROPY_MODULE_BUILTIN_INIT
    {MP_ROM_QSTR(MP_QSTR___init__),     MP_ROM_PTR(&this_init_fun_obj)},
    {MP_ROM_QSTR(MP_QSTR_ch),           MP_ROM_PTR(&this_ch_fun_obj)},
#else
    #error "__init__ not enabled: set MICROPY_MODULE_BUILTIN_INIT=1 to enable"
#endif /* MICROPY_MODULE_BUILTIN_INIT */
};

STATIC MP_DEFINE_CONST_DICT(
    mp_module_this_globals,
    this_globals_table
);

const mp_obj_module_t mp_module_this = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_this_globals,
};

MP_REGISTER_MODULE(MP_QSTR_this, mp_module_this);

#endif /* defined(MODULE_THIS_ENABLED) && MODULE_THIS_ENABLED */
