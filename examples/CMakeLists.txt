add_executable(teleport_scaffold_rigetti teleport_scaffold_rigetti.cpp)
target_link_libraries(teleport_scaffold_rigetti ${Boost_LIBRARIES} ${XACC_LIBRARIES} dl)

add_executable(qft_scaffold_rigetti qft_scaffold_rigetti.cpp)
target_link_libraries(qft_scaffold_rigetti ${Boost_LIBRARIES} ${XACC_LIBRARIES} dl)

add_executable(h2_exp_vals_scaffold_rigetti h2_exp_vals_scaffold_rigetti.cpp)
target_link_libraries(h2_exp_vals_scaffold_rigetti ${Boost_LIBRARIES} ${XACC_LIBRARIES} dl)

add_executable(h2_exp_vals_multi_exec h2_exp_vals_multi_exec.cpp)
target_link_libraries(h2_exp_vals_multi_exec ${Boost_LIBRARIES} ${XACC_LIBRARIES} dl)

