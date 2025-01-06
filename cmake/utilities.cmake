# --------------------------------------------------------------------------------------------------
# Utilities
#
# Everything here could be split further into smaller files, if needed.
# --------------------------------------------------------------------------------------------------

message(STATUS "Setup utilities")

# --------------------------------------------------------------------------------------------------
# Custom Functions
# --------------------------------------------------------------------------------------------------

# Print all arguments given to function
function(print)
    # For each argument given to this function...
    foreach (var ${ARGN})
        message("${var} = ${${var}}")
    endforeach ()
endfunction()