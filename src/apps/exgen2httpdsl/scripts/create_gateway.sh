#!/bin/bash

GATEWAY_NAME=$1
REGION_NAME=$2
LAMBDA_NAME=$3
ROLE_NAME=$4

TEMP="$(mktemp)"

function get_id() {
  grep -e '\<id\>' ${1} | cut -d\" -f 4
}

# Create the gateway
aws apigateway create-rest-api --name ${GATEWAY_NAME} --description 'Automatically created when deploying the lambda' > ${TEMP}

# we are going to need it's id for the rest of the operations here, to let's cache it
gatway_id=$(get_id ${TEMP})

# Get the resource id of the root of the gateway, we are configuring it to proxy all subpaths but not the root path
aws apigateway get-resources --rest-api-id ${gatway_id} > ${TEMP}
root_resource_id=$(get_id ${TEMP})

# Create the proxy resource for subpaths
aws apigateway create-resource --rest-api-id ${gatway_id} --region ${REGION_NAME} --parent-id ${root_resource_id} --path-part {proxy+} > ${TEMP}

proxy_resource_id=$(get_id ${TEMP})

# Put the any method, this can be more granular, but will suffice for now
aws apigateway put-method --rest-api-id ${gatway_id} --resource-id ${proxy_resource_id} --http-method ANY --authorization-type NONE

#get the Role ARN
# role_arn=$(aws iam get-role --role-name ${ROLE_NAME} | grep Arn | cut -d\" -f 4)
# This is getting the role of the lambda, and does not work, leaving the credentials empty seems to do the trick

#get the lambda ARN
lambda_arn=$(aws lambda get-function --function-name ${LAMBDA_NAME} | grep FunctionArn | cut -d\" -f4)

# Now assign the method to the lambda
aws apigateway put-integration --region ${REGION_NAME} --rest-api-id ${gatway_id} --resource-id ${proxy_resource_id} --http-method ANY --type AWS_PROXY --integration-http-method POST --uri arn:aws:apigateway:us-east-2:lambda:path/2015-03-31/functions/${lambda_arn}/invocations #--credentials ${role_arn}

# At this point we have the integration, but we need to allow the gateway to invoke the method, still not sure how to do this from here, for the time being, save the lambda in the integration page this will prompt the permissions
