EXECUTABLES += exgen2httpdsl

DIR_EXES += exgen2httpdsl
exgen2httpdsl_SHARED_MODULES += httpdsl
exgen2httpdsl_SHARED_MODULES += httpdsl_providers

exgen2httpdsl_OBJS += exgen2httpdsl
exgen2httpdsl_OBJS += exgen2httpdsl_config
exgen2httpdsl_OBJS += exgen2httpdsl_generator

exgen2httpdsl_MODULES += exgen_displays
exgen2httpdsl_MODULES += mathex
exgen2httpdsl_MODULES += cursex
exgen2httpdsl_MODULES += xml
exgen2httpdsl_MODULES += svg
exgen2httpdsl_MODULES += xgen

DIR_COMPILATION_FLAGS += -I$(strip ${LAMBDA_LINK_LIBS})/aws_lambda_cpp/include
DIR_COMPILATION_FLAGS += -I$(strip ${LAMBDA_LINK_LIBS})/aws_sdk_cpp/include
DIR_COMPILATION_FLAGS += -I$(strip ${LAMBDA_LINK_LIBS})/httpdsl/include/httpdsl
DIR_COMPILATION_FLAGS += -I$(strip ${LAMBDA_LINK_LIBS})/httpdsl/include/providers
DIR_COMPILATION_FLAGS += -Isrc/mathex
DIR_COMPILATION_FLAGS += -Isrc/xgen
DIR_COMPILATION_FLAGS += -Isrc/exgen

LDFLAGS += -L$(strip ${LAMBDA_LINK_LIBS})/aws_lambda_cpp/lib
LDFLAGS += -L$(strip ${LAMBDA_LINK_LIBS})/aws_sdk_cpp/lib64
LDFLAGS += -L$(strip ${LAMBDA_LINK_LIBS})/httpdsl/lib
LDFLAGS += -laws-cpp-sdk-core
LDFLAGS += -laws-lambda-runtime
LDFLAGS += -lcrypto
LDFLAGS += -lcurl

LAMBDA_SCRIPTS_DIR := src/apps/exgen2httpdsl/scripts
LAMBDA_PACKAGER_PATH := $(strip ${LAMBDA_LINK_LIBS})/aws_lambda_cpp/lib/aws-lambda-runtime/cmake/packager

EXGEN_HTTPDSL_ROLE_NAME := exgen_httpdsl_role
EXGEN_HTTPDSL_LAMBDA_NAME := exgen_httpdsl_lambda
EXGEN_HTTPDSL_REGION_NAME := us-east-2
EXGEN_HTTPDSL_GATEWAY_NAME := exgen_httpdsl_gateway
EXGEN_HTTPDSL_ZIP_FILE := exgen2httpdsl.exe.zip
EXGEN_HTTPDSL_ZIP_FILE_PATH := $(shell "pwd")

exgen_httpdsl_deployment: package_exgen_httpdsl_lamnda create_exgen_httpdsl_lambda deploy_exgen_httpdsl_gateway

create_exgen_httpdsl_lambda:
	${QQ}./$(strip ${LAMBDA_SCRIPTS_DIR})/create_lambda.sh ${EXGEN_HTTPDSL_ROLE_NAME} ${EXGEN_HTTPDSL_LAMBDA_NAME} exgen2httpdsl.exe ${EXGEN_HTTPDSL_ZIP_FILE}
	${QQ}${RM_F} ${EXGEN_HTTPDSL_ZIP_FILE}

package_exgen_httpdsl_lamnda:
	${QQ}$(strip ${LAMBDA_PACKAGER_PATH}) $(strip ${OUTDIR})/exe/exgen2httpdsl.exe
	pushd $(strip ${LAMBDA_LINK_LIBS})/httpdsl && zip -rv ${EXGEN_HTTPDSL_ZIP_FILE_PATH}/${EXGEN_HTTPDSL_ZIP_FILE} lib/libhttpdsl.so
	pushd $(strip ${LAMBDA_LINK_LIBS})/httpdsl  && zip -rv ${EXGEN_HTTPDSL_ZIP_FILE_PATH}/${EXGEN_HTTPDSL_ZIP_FILE} lib/libhttpdsl_providers.so

deploy_exgen_httpdsl_gateway:
	${QQ}./$(strip ${LAMBDA_SCRIPTS_DIR})/create_gateway.sh ${EXGEN_HTTPDSL_GATEWAY_NAME} ${EXGEN_HTTPDSL_REGION_NAME} ${EXGEN_HTTPDSL_LAMBDA_NAME} ${EXGEN_HTTPDSL_ROLE_NAME}

update_exgen_httpdsl_lambda: package_exgen_httpdsl_lamnda
	${QQ}aws lambda update-function-code --function-name ${EXGEN_HTTPDSL_LAMBDA_NAME} --zip-file fileb://$(strip ${EXGEN_HTTPDSL_ZIP_FILE})
	${QQ}${RM_F} ${EXGEN_HTTPDSL_ZIP_FILE}

delete_exgen_httpdsl_lambda:
	${QQ}aws iam delete-role --role-name ${EXGEN_HTTPDSL_ROLE_NAME}
	${QQ}aws lambda delete-function --function-name ${EXGEN_HTTPDSL_LAMBDA_NAME}

CLEAN_STAGING_TARGETS += delete_exgen_httpdsl_lambda

# vim: set noexpandtab :

