file(REMOVE_RECURSE
  "project2/main.qml"
  "project2/pages/about.qml"
  "project2/pages/editProfile.qml"
  "project2/pages/home.qml"
  "project2/pages/profile.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appproject2_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
