#ifndef HTMLREADER_H
#define HTMLREADER_H

#include <string>
#include <fstream>
#include "document.h"
#include "nodes/rendernode.h"
#include "nodes/paragraphnode.h"
#include "nodes/headnode.h"
#include "nodes/bodynode.h"

class HTMLReader
{
public:
    HTMLReader();
    ~HTMLReader();
    void paint();
    void prepareDocument(std::string HTMLFilepath);

    //These are defined by the W3C HTML5 parser specification.
    enum parseState {
        initialMode,
        beforeHTML,
        beforeHead,
        inHead,
        inHeadNoscript,
        afterHead,
        inBody,
        text,
        inTable,
        inTableText,
        inCaption,
        inColumnGroup,
        inTableBody,
        inRow,
        inCell,
        inSelect,
        inSelectInTable,
        afterBody,
        inFrameset,
        afterFrameset,
        afterAfterBody,
        afterAfterFrameset,
        tagOpen,
        endTagOpen,
        tagName,
        endTagName,
        bogusComment,
        doctypeDeclaration
    };

    std::string returnTagName(std::string::iterator &i,
                              parseState &currentState);
    RenderNode* createNode(std::string nodeName, std::string::iterator &i,
                           parseState &currentState);
    ParagraphNode* createParagraphNode(std::string::iterator &i,
                                       parseState &currentState);
    HeadNode* createHeadNode();
    BodyNode* createBodyNode();


private:
    Document *webpage;
    RenderNode *currentParentNode;
    RenderNode *currentNode;
    void parseDocumentText(std::string documentText);
    bool parentNodeClosed(RenderNode *node, std::string typeOfNode);
};

#endif // HTMLREADER_H
