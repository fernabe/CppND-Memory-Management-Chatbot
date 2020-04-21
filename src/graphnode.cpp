#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //Task 0
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //_childEdges.push_back(edge);
    _childEdges.push_back(std::move(edge));

}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // Task 5
    //_chatBot = chatbot;
    _chatBot = std::move(chatbot);
    //_chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // Task 5
    //newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];

    // Task 4
    return _childEdges[index].get();
    
    ////
    //// EOF STUDENT CODE
}