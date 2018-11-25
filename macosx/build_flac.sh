P=x86_64-apple-darwin17

PKG=$P-pkg-config
MYCFLAGS="-mmacosx-version-min=10.7 -stdlib=libc++ -mtune=generic -mfpmath=sse -msse2 -fvisibility=default -g -O2 `$PKG --cflags ogg`"

LIBDIR=/opt/local/lib

LDFLAG="$LIBDIR/libogg.a" CFLAGS="$MYCFLAGS" CPPFLAGS="$MYCPPFLAGS" CC=o64-clang AR=$P-ar RANLIB=$P-ranlib ./configure --host=$P --enable-static --disable-shared --disable-ogg 
make -j8

