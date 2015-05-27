// Module for cryptography

//#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "platform.h"
#include "auxmods.h"
#include "lrotable.h"

#include "c_types.h"
#include "user_interface.h"

/**
  * crypto.function1()
  * Description:
  * 	prints "crypto.function1()" to output
  *
  * Syntax:
  * 	crypto.function1()
  * Parameters:
  * 	nil
  * Returns:
  * 	nil
  */

static int function1( lua_State* L )
{
	c_printf("crypto.function1()\n");
	return 0;
}

/**
  * crypto.function2()
  * Description:
  * 	prints "crypto.function2()" to output
  * Syntax:
  * 	crypto.function1()
  * Parameters:
  * 	nil
  * Returns:
  * 	nil
  */

static int function2( lua_State* L )
{
	c_printf("crypto.function2()\n");
	return 0;
}

// Module function map
#define MIN_OPT_LEVEL 2
#include "lrodefs.h"
const LUA_REG_TYPE crypto_map[] =
{
  { LSTRKEY( "function1" ), LFUNCVAL( function1 ) },
  { LSTRKEY( "function2" ), LFUNCVAL( function2 ) },
#if LUA_OPTIMIZE_MEMORY > 0

#endif
  { LNILKEY, LNILVAL }
};

LUALIB_API int luaopen_crypto( lua_State *L )
{
#if LUA_OPTIMIZE_MEMORY > 0
  return 0;
#else // #if LUA_OPTIMIZE_MEMORY > 0
  luaL_register( L, AUXLIB_CRYPTO, crypto_map );
  // Add constants

  return 1;
#endif // #if LUA_OPTIMIZE_MEMORY > 0
}
