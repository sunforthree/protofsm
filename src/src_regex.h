#ifndef _SRC_REGEX_H_
#define _SRC_REGEX_H_

#include <iostream>

namespace sunfor3 {

#ifdef PROTOFSM_NOSTDLIB
    /* 
     * remove dependency on standard library (silent fail!).
     * useful in conjunction with -nostdlib option, e.g. if your compiler
     * does not provide a standard library.
     * NOTE: this silently disables all static_assert() calls below!
     */
    template<typename T, typename S>
    struct is_same_dfa { static constexpr bool value = true; };
#else
    /* Check if both input and dfa share same type */
    template<typename I, typename D>
    struct is_same_type : std::is_same<typename I::dfatype, typename D::dfatype> { };
#endif

} /* namespace sunfor3 */

#endif