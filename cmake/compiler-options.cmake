# --------------------------------------------------------------------------------------------------
# Setup compiler
# --------------------------------------------------------------------------------------------------

message("Setup compiler")

set(STRICT_COMPILE_OPTIONS
        -pedantic
        -Wall
        -Wextra
        -Wold-style-cast
        -Wcast-align
        -Wcast-qual
        -Wctor-dtor-privacy
        -Wdisabled-optimization
        -Wformat=2
        -Winit-self
        -Wlogical-op
        -Wmissing-declarations
        -Wmissing-include-dirs
        -Wnoexcept
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-compare
        -Wsign-promo
        -Wstrict-null-sentinel
        -Wstrict-overflow=3
        #    -Wswitch-default
        -Wundef
        -Wno-unused
        -Weffc++
        -Werror
        #     -v -dD
)

mark_as_advanced(STRICT_COMPILE_OPTIONS)