FILE(REMOVE_RECURSE
  "CMakeFiles/sonar_generate_messages_py"
  "/home/odroid/quad_ws/devel/lib/python2.7/dist-packages/sonar/msg/_SonarData.py"
  "/home/odroid/quad_ws/devel/lib/python2.7/dist-packages/sonar/msg/__init__.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/sonar_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
