include("D:/rwth_eclipse_workstation/Versuch9/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Versuch9-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/rwth_eclipse_workstation/Versuch9/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/Versuch9.exe
    GENERATE_QT_CONF
)
