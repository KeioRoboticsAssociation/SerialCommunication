import shutil
import time

while True:
    time.sleep(0.5)
    with open(".vscode/c_cpp_properties.json", "r") as f:
        if f.readline() == '//\n':
            shutil.copy(".vscode/c_cpp_properties_copy.json", ".vscode/c_cpp_properties.json")
            print("copied .vscode/c_cpp_properties_copy.json into .vscode/c_cpp_properties.json")
            #break
        
        
