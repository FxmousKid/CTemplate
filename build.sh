#!/usr/bin/env bash

up()
{ 
	printf '%s' "$1" | tr '[:lower:]' '[:upper:]'; 
}

# repl [PLACEHOLER] [VARNAME] [FILE] 
# expands to :
#    sed -e "s/{{CT_PROJECT_NAME}}/${project_name}/g" $file > $TMP
#    sed -e "s/{{CT_PROJECT_NAME}UPPER}/$(up ${project_name})/g" $file > $TMP
repl()
{
	sed  \
		-e "s/{{$1}}/$2/g" \
		-e "s/{{$1}UPPER}/$(up "$2")/g" \
		$3 > $TMP
	cp $TMP $file
}

repl_project_name()
{
	local CT_PROJECT_NAME_FILES="CMakeLists.txt .gitignore src/utils/misc.c"
	local project_name
	printf "%s" "Enter the project name : "
	read project_name

	for file in ${CT_PROJECT_NAME_FILES}; do
		repl "CT_PROJECT_NAME" "$project_name" "$file"
	done
}

main()
{
	# temp file to circumvent sed -i discrepancies across BSD/MacOS and linux
	TMP="tmp.$(date +%s)" 
	touch $TMP

	repl_project_name

	rm $TMP
	printf "Done !\n"
}

main
