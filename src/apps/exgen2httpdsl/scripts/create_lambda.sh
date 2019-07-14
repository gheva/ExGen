#!/bin/bash

ROLE_NAME=$1
LAMBDA_NAME=$2
LAMBDA_HANDLER=$3
LAMBDA_ZIP=$4


trust_policy_json=$(cat << 'END_POLICY_JSON'
{
  "Version": "2012-10-17", 
    "Statement": [ 
      { "Effect": "Allow", "Principal":
        { "Service": ["lambda.amazonaws.com"] },
        "Action": "sts:AssumeRole" } ] 
}
END_POLICY_JSON
)

policy_file="$(mktemp)"

echo $trust_policy_json > $policy_file

aws iam create-role --role-name ${ROLE_NAME} --assume-role-policy-document "file://${policy_file}"

# let the role time to fully be created
sleep 30
role_arn=$(aws iam get-role --role-name ${ROLE_NAME} | grep Arn | cut -d\" -f 4)

aws lambda create-function --function-name ${LAMBDA_NAME} --role $role_arn --runtime provided --timeout 15 --memory-size 128 --handler ${LAMBDA_HANDLER} --zip-file fileb://$LAMBDA_ZIP

